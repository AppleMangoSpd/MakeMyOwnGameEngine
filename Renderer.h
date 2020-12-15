#include <vector>
#include <windows.h>
#include "ICleanUp.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"

class Object;
class RenderableObject;
class GLFWwindow;
class IUpdater;
class IRenderer;

class Renderer : public ICleanUp
{
public:
	Renderer() : _isEnd(false) {}
	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}
public:
	void addObject(RenderableObject* _added);
	void init();
	void setRenderFrameRate(double _input);
	void render(RenderableObject* src_obj);
	void render();

	void update(IUpdater* render_obj);

	bool canUpdate();
	bool canRender();

	void setCameraPosition(glm::vec3 _input);
	virtual void shutDown() override;
	
	GLFWwindow* getWindow() const { return window; }

	void setEnd() { _isEnd = true; };
	bool isEnd() const { return _isEnd; };
private:
	LARGE_INTEGER _frameInfo;
	LARGE_INTEGER _prevFrameCounter;
	LARGE_INTEGER _nowFrameCounter;

	double _renderFrameRate;

	bool _isEnd;

	std::vector<RenderableObject*> renderableObjectVec;
	glm::vec3 cameraPosition;
	GLFWwindow* window;
};