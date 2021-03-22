#ifndef SCENEMENU_H
#define SCENEMENU_H

#include "Scene.h"

class SceneMenu : public Scene {
	public:
		enum MenuOptions{CONTINUE, NEW_GAME, EXIT};
		SceneMenu();
		~SceneMenu();
		virtual void preLoad();
		virtual void unLoad();
	protected:
		virtual void init();
	
		virtual void updateBegin();
		virtual void update();
		virtual void updateEnd();
	
		virtual void renderBegin();
		virtual void render();
		virtual void renderEnd();
	
		virtual void renderGUI();
	
	private:
		int			menu_img_id;
		C_Rectangle menu_img_rect;

		int			mMenuOption;
		C_Rectangle mOptionSelector;
};

#endif