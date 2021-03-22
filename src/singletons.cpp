#include "singletons.h"

Renderer*			sRenderer = NULL;
Input*				sInput = NULL;
ResourceManager*	sResManager = NULL;
SceneDirector*		sDirector = NULL;

void initSingletons() {
	sRenderer = Renderer::getInstance();
	sInput = Input::getInstance();
	sResManager = ResourceManager::getInstance();
	sDirector = SceneDirector::getInstance();

	sRenderer->setFramerate(60);
	sInput->setWindow(sRenderer->getWindow());
}