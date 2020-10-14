#include "ICleanUp.h"

#include "include/GL/glew.h"
#include "glm/glm.hpp"

class Object;
class RenderableObject;
class GLFWwindow;

class Renderer : public ICleanUp
{
public:
	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}
public:
	void init();
	void render(RenderableObject* src_obj);

	void setCameraPosition(glm::vec3 _input);
	virtual void shutDown() override;
private:
	glm::vec3 cameraPosition;
	GLFWwindow* window;
};