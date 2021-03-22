#ifndef SCENE_H
#define SCENE_H

#include "Utils.h"

class Scene {
	public:
		Scene();
		~Scene();
	
		virtual void preLoad();
		virtual void unLoad(); //Free memory
		void onLoad();
		void onUpdate();
		void onRender();

		void setLoaded(bool load);
	protected:
		virtual void init();

		virtual void updateBegin();
		virtual void update();
		virtual void updateEnd();

		virtual void renderBegin();
		virtual void render();
		virtual void renderEnd();

		virtual void renderGUI();

		bool mSceneLoaded;
};
#endif
