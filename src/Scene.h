#ifndef SCENE_H
#define SCENE_H

#include "Utils.h"

class Scene {
public:
	Scene();
	~Scene();

	virtual void preLoad();
	virtual void unLoad(); //Liberar memoria sin borrar un puntero
	void onLoad();
	void onUpdate();
	void onRender();

	void setLoaded(bool load);
	void leaveScene();

protected:
	virtual void init();
	virtual void enterScene();

	virtual void updateBegin();
	virtual void update();
	virtual void updateEnd();

	virtual void renderBegin();
	virtual void render();
	virtual void renderEnd();

	virtual void renderGUI();

	bool mSceneLoaded;
	bool mSceneEntered;
};

#endif