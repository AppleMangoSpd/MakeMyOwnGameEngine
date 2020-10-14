#include "Sphere.h"

Sphere::Sphere(GLuint _vertexArrayID, GLuint _programID,
	GLuint _matrixID, GLuint _viewMatrixID, GLuint _modelMatrixID, 
	GLuint _texture, GLuint _textureID, 
	std::vector<glm::vec3> _vertices, 
	std::vector<glm::vec2> _uvs, 
	std::vector<glm::vec3> _normals, 
	GLuint _vertexbuffer, GLuint _uvbuffer, GLuint _normalbuffer,
	GLuint _lightID)
{
	VertexArrayID = _vertexArrayID;
	programID = _programID;

	MatrixID = _matrixID;
	ViewMatrixID = _viewMatrixID;
	ModelMatrixID = _modelMatrixID;
	
	Texture = _texture;
	TextureID = _textureID;

	vertices = _vertices;
	uvs = _uvs;
	normals = _normals;

	vertexbuffer = _vertexbuffer;
	uvbuffer = _uvbuffer;
	normalbuffer = _normalbuffer;
	LightID = _lightID;
}
