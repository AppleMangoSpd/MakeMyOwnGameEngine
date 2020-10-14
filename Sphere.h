#pragma once
#include "Object.h"
class Sphere :
    public RenderableObject
{
public:
    Sphere() {};
	Sphere(GLuint _vertexArrayID, GLuint _programID,
		GLuint _matrixID, GLuint _viewMatrixID, GLuint _modelMatrixID,
		GLuint _texture, GLuint _textureID,
		std::vector<glm::vec3> _vertices,
		std::vector<glm::vec2> _uvs,
		std::vector<glm::vec3> _normals,
		GLuint _vertexbuffer, GLuint _uvbuffer, GLuint _normalbuffer,
		GLuint _lightID);

};

