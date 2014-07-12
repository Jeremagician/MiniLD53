#include "Scene.hpp"

using namespace sf;
using namespace std;

void Scene::setInputHandler(InputHandler::Ptr newInputHandler)
{
	// Since we use shared pointer, old input handler
	// is properly released and free'd if needed
	inputHandler = newInputHandler;
}

InputHandler::Ptr Scene::getInputHandler(void)
{
	// Return a copy of the shared pointer
	// and increments shared pointer reference count
	return inputHandler;
}

bool Scene::hasInputHandler(void)
{
	return inputHandler.use_count() > 0;
}
