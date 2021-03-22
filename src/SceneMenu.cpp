#include "singletons.h"
#include "SceneMenu.h"

SceneMenu::SceneMenu() : Scene() {

}

SceneMenu::~SceneMenu() {

}

void SceneMenu::preLoad() {

}

void SceneMenu::init() {

}

void SceneMenu::updateBegin() {
}

void SceneMenu::update() {
	if (sInput->isKeyPressed(Input::SPACE)) {
		sDirector->changeScene(SceneDirector::GAME);
	}
}

void SceneMenu::updateEnd() {

}

void SceneMenu::renderBegin() {

}

void SceneMenu::render() {
	sRenderer->drawSprite(sprite_id, 50, 50, sprite_rect);

	sRenderer->drawRectangle(rect1, Color{ 255,0,0 }, true);
	//sRenderer->drawRectangle(rect2, Color{ 0,255,0 });
}

void SceneMenu::renderEnd() {

}

void SceneMenu::renderGUI() {

}