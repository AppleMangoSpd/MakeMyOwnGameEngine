#include <stdio.h>

#include "Renderer.h"
#include "Object.h"
#include "include/GLFW/glfw3.h" 

#include "glm/gtc/matrix_transform.hpp"

void Renderer::addObject(RenderableObject* _added)
{
	renderableObjectVec.push_back(_added);
}

void Renderer::init()
{
	//GLFW 초기화
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Mac OS와 관련된 코드?
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Custom Engine Sample", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr,
			"Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version"
		);
		getchar();
		glfwTerminate(); //종료 관련 기능?
		return;
	}
	glfwMakeContextCurrent(window);

	//GLEW 초기화
	glewExperimental = true; //코어 프로필에 필요?
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	//esc키 눌렸는지
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//포인터 숨기고 마우스의 움직임 제한없이?
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//마우스를 화면 중앙으로
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	//배경색 지정
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Depth 사용할것
	glEnable(GL_DEPTH_TEST);
	//Depth 사용 함수 설정
	glDepthFunc(GL_LESS);
	//Cull 사용하럿
	glEnable(GL_CULL_FACE);

	_frameInfo.QuadPart = 0;
	_prevFrameCounter.QuadPart = 0;
	_nowFrameCounter.QuadPart = 0;
	_renderFrameRate = 60;
}

void Renderer::setRenderFrameRate(double _input)
{
	this->_renderFrameRate = _input;
}

void Renderer::render(RenderableObject* src_obj)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use our shader
	glUseProgram(src_obj->programID);

	// Compute the MVP matrix from keyboard and mouse input
	glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 ViewMatrix = glm::lookAt(
		cameraPosition, // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	glm::mat4 ModelMatrix = glm::translate(glm::mat4(1.0), src_obj->Position);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(src_obj->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(src_obj->ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
	glUniformMatrix4fv(src_obj->ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

	glm::vec3 lightPos = glm::vec3(0, 0, 10);
	glUniform3f(src_obj->LightID, lightPos.x, lightPos.y, lightPos.z);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, src_obj->Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(src_obj->TextureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// Draw the triangles !
	glDrawArrays(GL_TRIANGLES, 0, src_obj->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	// Swap buffers
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Renderer::render()
{
	std::vector<RenderableObject*>::iterator iter;
	iter = renderableObjectVec.begin();
	while (iter != renderableObjectVec.end())
	{
		//(*iter)->render();
		this->render(*iter);
		++iter;
	}
}

void Renderer::update(IUpdater* src_obj)
{
	src_obj->update();
}

bool Renderer::canUpdate()
{
	QueryPerformanceFrequency(&_frameInfo);
	QueryPerformanceCounter(&_prevFrameCounter);

	// fps 60 고정
	double _perFrame = _frameInfo.QuadPart / 60;

	QueryPerformanceCounter(&_nowFrameCounter);

	double time_distance = _nowFrameCounter.QuadPart - _prevFrameCounter.QuadPart;

	if (time_distance > _perFrame)
	{
		_prevFrameCounter = _nowFrameCounter;
		
		return true;
	}
	return false;
}

bool Renderer::canRender()
{
	QueryPerformanceFrequency(&_frameInfo);
	QueryPerformanceCounter(&_prevFrameCounter);

	// 가변 기준은 어떻게?
	double _perFrame = _frameInfo.QuadPart / _renderFrameRate;

	QueryPerformanceCounter(&_nowFrameCounter);

	double time_distance = _nowFrameCounter.QuadPart - _prevFrameCounter.QuadPart;

	if (time_distance > _perFrame)
	{
		_prevFrameCounter = _nowFrameCounter;

		return true;
	}
	return false;
}

void Renderer::setCameraPosition(glm::vec3 _input)
{
	cameraPosition = _input;
}

void Renderer::shutDown()
{
	std::vector<RenderableObject*>::iterator iter;
	iter = renderableObjectVec.begin();
	while (iter != renderableObjectVec.end())
	{
		(*iter)->shutDown();
	}
	glfwTerminate();
}
