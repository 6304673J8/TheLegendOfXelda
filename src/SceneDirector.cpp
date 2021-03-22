#include "SceneDirector.h"

//Include Scenes of game
#include "SceneMenu.h"
#include "SceneGame.h"
//#include "SceneOver.h"

SceneDirector* SceneDirector::instance = NULL;

SceneDirector* SceneDirector::getInstance() {
	if (instance == NULL) {
		instance = new SceneDirector();
	}
	return instance;
}

SceneDirector::SceneDirector(){
	if (instance != NULL) { return; }
	//initScenes();
}

SceneDirector::~SceneDirector(){

}

void SceneDirector::initScenes(){
	mScenes.resize(SceneDirector::LAST_NO_USE);

	SceneMenu* scene_menu = new SceneMenu();	
	SceneGame* scene_game = new SceneGame();

	mScenes[MAIN_MENU] = scene_menu;
	mScenes[GAME] = scene_game;

	for (int i = 0; i < LAST_NO_USE; i++) {
		mScenes[i]->preLoad();
	}
	mCurrentScene = mScenes[FIRST_SCENE]; // Escena Inicial
}

void SceneDirector::changeScene(SceneEnum next_scene, bool load_on_return, bool history){
	if (load_on_return) { mCurrentScene->unLoad(); }
	mCurrentScene->setLoaded(!load_on_return);
	if (history) {
		mSceneHistory.push(mCurrentScene);
	}
	mCurrentScene = mScenes[next_scene];
}

void SceneDirector::goBack(bool load_on_return){
	if (load_on_return) { mCurrentScene->unLoad(); }
	if (mSceneHistory.empty()) { return; }
	Scene* prevScene = mSceneHistory.top();
	if (prevScene != NULL) {
		mSceneHistory.pop();
		mCurrentScene->setLoaded(!load_on_return);
		mCurrentScene = prevScene;
	}
}