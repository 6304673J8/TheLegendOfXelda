#include "singletons.h"
#include "Scene.h"

unsigned int global_delta_time = 0;
Scene* currentScene = NULL;

void mainLoop() {
	const clock_t begin_time = clock();
	clock_t old_time = begin_time;
	clock_t new_time = begin_time;

	while (sRenderer->windowIsOpen()) {
		//Delta time update
		old_time = new_time;
		new_time = clock() - begin_time;
		global_delta_time = int(new_time - old_time);

		//Delta Input Update
		sInput->updateEvents();

		//Scene Update and Draw
		currentScene = sDirector->getCurrentScene();
		if (currentScene != NULL) {
			currentScene->onLoad();
			currentScene->onUpdate();
			currentScene->onRender();
		}

		//Pintar Cosas

		//Acaba de pintar cosas
		//sRenderer->windowRefresh();
	}
}

int main()
{
	initSingletons();
	mainLoop();
	system("Pause");
	return 0;
}