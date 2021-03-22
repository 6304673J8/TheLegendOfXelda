#include "Scene.h"
#include "singletons.h"

Scene::Scene() {
	mSceneLoaded = false;
}
Scene::~Scene() {

}
void Scene::onLoad() {
	if (!mSceneLoaded) {
		init();
		setLoaded(true);
	}
}
void Scene::onUpdate() {
	if (!mSceneLoaded) { return; }
	updateBegin();
	update();
	updateEnd();
}
void Scene::onRender() {
	if (!mSceneLoaded) { return; }
	sRenderer->windowClear();

	renderBegin();
	render();
	renderEnd();
	renderGUI();

	sRenderer->windowRefresh();
}

void Scene::setLoaded(bool load) {
	mSceneLoaded = load;
}

void Scene::preLoad() {

}

void Scene::unLoad() {
	
}

void Scene::init(){}
void Scene::updateBegin() {}
void Scene::update() {}
void Scene::updateEnd() {}
void Scene::renderBegin() {}
void Scene::render() {}
void Scene::renderEnd() {}
void Scene::renderGUI() {}
