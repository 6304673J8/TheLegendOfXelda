#ifndef RENDERER_H
#define RENDERER_H

#include "includes.h"
#include <SFML/Graphics.hpp>

class Renderer {
	public:
		Renderer();
		~Renderer();
	
		//! Initialize the screen
		void initWindow();

		//! Clean Window
		void windowClear();

		//! Performs Screen Draw (screen flip)
		void windowRefresh();

		//! Window Is Open
		bool windowIsOpen();

		//! Rectangle Shape Draw
		void drawRectangle(C_Rectangle rect, Color col, bool outline);
		
		//! Sprite Draw
		void drawSprite(int ID, int posX, int posY, C_Rectangle rect);

		//! Returns the windows pointer
		sf::RenderWindow* getWindow() { return mWindow; };

		void setFramerate(int framerate);
		//! This class is Singleton
		static Renderer* getInstance();

	private:
		static Renderer* instance;

		sf::RenderWindow*	mWindow;
		int					mWindowWidth;
		int					mWindowHeight;
};
#endif