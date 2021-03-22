#include "Renderer.h"
#include "singletons.h"

Renderer* Renderer::instance = NULL;

Renderer* Renderer::getInstance() {
	if (instance == NULL) {
		instance = new Renderer();
	}
	return instance;
}

Renderer::Renderer() {
	if (instance != NULL) { return; }
	mWindow = NULL;
	initWindow();
}
Renderer::~Renderer() {

}

void Renderer::initWindow() {
	mWindowWidth = SCREEN_WIDTH;
	mWindowHeight = SCREEN_HEIGHT;

	mWindow = new sf::RenderWindow(sf::VideoMode(mWindowWidth,mWindowHeight), WINDOW_TITLE);
}

void Renderer::setFramerate(int framerate) {
	mWindow->setFramerateLimit(framerate);
}

void Renderer::windowClear() {
	mWindow->clear(sf::Color::Black);
}

void Renderer::windowRefresh() {
	mWindow->display();
}

bool Renderer::windowIsOpen() {
	return mWindow->isOpen();
}

void Renderer::drawRectangle(C_Rectangle rect, Color col, bool outline) {
	sf::RectangleShape shape_rect;
	sf::Color color = sf::Color(col.r, col.g, col.b);
	if (!outline) {
		shape_rect.setFillColor(color);
	}
	else {
		shape_rect.setFillColor(sf::Color(0, 0, 0, 0));
	}
	shape_rect.setOutlineThickness(1);
	shape_rect.setOutlineColor(color);
	shape_rect.setPosition(sf::Vector2f(rect.x, rect.y));
	shape_rect.setSize(sf::Vector2f(rect.w, rect.h));

	mWindow->draw(shape_rect);
}

void Renderer::drawSprite(int ID, int posX, int posY, C_Rectangle rect) {
	if (ID == -1) {
		return;
	}
	sf::Sprite* spr = sResManager->getSpriteByID(ID);
	spr->setTextureRect(sf::IntRect(rect.x, rect.y, rect.w, rect.h));
	spr->setPosition(sf::Vector2f(posX, posY));

	mWindow->draw(*spr);
}