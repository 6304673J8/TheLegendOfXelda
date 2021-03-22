#include "SceneMenu.h"
#include "singletons.h"

SceneMenu::SceneMenu() : Scene() {

}

SceneMenu::~SceneMenu() {

}

void SceneMenu::preLoad() {

}

void SceneMenu::unLoad() {

}

void SceneMenu::init(){
	menu_img_id = sResManager->getSpriteID("assets/sanic.png");
	menu_img_rect = C_Rectangle{ 0, 0, 
		sResManager->getSpriteWidth(menu_img_id),
		sResManager->getSpriteHeight(menu_img_id),
	};

	mMenuOption = CONTINUE;
	mOptionSelector = C_Rectangle{ 700,250,180,30 };
}

void SceneMenu::updateBegin(){

}

void SceneMenu::update(){
	int prevOption = mMenuOption;
	if (sInput->isKeyPressed(Input::ARROW_DOWN)) {
		mMenuOption++;
		if (mMenuOption > EXIT) {
			mMenuOption = EXIT;
		}
	}
	else if (sInput->isKeyPressed(Input::ARROW_UP)) {
		mMenuOption--;
		if (mMenuOption < CONTINUE) {
			mMenuOption = CONTINUE;
		}
	}
	if (prevOption != mMenuOption) {
		mOptionSelector.y = 250 + mMenuOption * 50;
	}
	if (sInput->isKeyPressed(Input::ENTER)) {
		switch (mMenuOption) {
			switch (mMenuOption) {
			default:break;
			case NEW_GAME:
				sDirector->changeScene(SceneDirector::GAME, false);
				break;
			case EXIT:
				break;
			}
		}
	}
}

void SceneMenu::updateEnd() {

}

void SceneMenu::renderBegin() {

}

void SceneMenu::render() {
	sRenderer->drawSprite(menu_img_id, 0, 0, menu_img_rect);
	sRenderer->drawRectangle(mOptionSelector, Color{ 255, 255, 255 }, true);
}

void SceneMenu::renderEnd(){

}

void SceneMenu::renderGUI(){}