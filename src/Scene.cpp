#include "Scene.hpp"

using namespace sf;
using namespace std;

void Scene::draw(RenderTarget &target, RenderStates states) const
{

}

void Scene::setInputHandler(InputHandler::Ptr newInputHandler)
{
	inputHandler = newInputHandler;
}

InputHandler::Ptr Scene::getInputHandler(void)
{
	return inputHandler;
}

bool Scene::hasInputHandler(void)
{
	return inputHandler.use_count() > 0;
}
