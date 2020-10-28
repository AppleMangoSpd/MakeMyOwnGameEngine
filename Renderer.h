#include <vector>

#include "ICleanUp.h"

#include "include/GL/glew.h"
#include "glm/glm.hpp"

class Object;
class RenderableObject;
class GLFWwindow;
class IUpdater;
class IRenderer;

class Renderer : public ICleanUp
{
public:
	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}
public:
	void addObject(RenderableObject* _added);
	void init();
	void render(RenderableObject* src_obj);
	void render();

	void update(IUpdater* render_obj);

	void setCameraPosition(glm::vec3 _input);
	virtual void shutDown() override;
private:
	std::vector<RenderableObject*> renderableObjectVec;
	glm::vec3 cameraPosition;
	GLFWwindow* window;
};