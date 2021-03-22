#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager* ResourceManager::getInstance() {
	if (!instance) {
		instance = new ResourceManager();
	}
	return instance;
}

ResourceManager::ResourceManager() {
	if (instance != NULL) { return; }
	mFirstFreeSlot = 0;
}

ResourceManager::~ResourceManager() {

}

int ResourceManager::getSpriteID(const char* filepath) {
	int texture_id = getTextureID(filepath);
	if (texture_id != -1) {
		std::map<std::string, sf::Sprite*>::iterator it = mSpritesMap.find(filepath);
		if (it == mSpritesMap.end()) {
			sf::Sprite* spr = new sf::Sprite();
			spr->setTexture(*getTextureByID(texture_id));
			mSpritesMap.insert(std::pair<std::string, sf::Sprite*>(filepath, spr));
			int returnValue = 0;
			mSpritesVector.push_back(spr);
			returnValue = mSpritesVector.size() - 1;
			return returnValue;
		}else {
			return searchSprite(it->second);
		}
	}
}

int ResourceManager::getTextureID(const char* filepath) {
	std::map<std::string, sf::Texture*>::iterator it = mTexturesMap.find(filepath);
	int returnValue = -1;
	if (it == mTexturesMap.end()) {
		std::cout << "Adding Texture " << filepath << "(first request)" << std::endl;
		int index = addTexture(filepath);
		mIDMap.insert(std::pair<std::string, int>(filepath, index));
		returnValue = index;
	}else {
		std::map<std::string, int>::iterator iter = mIDMap.find(filepath);
		if (iter == mIDMap.end()) {
			std::cout << "Failed to find " << filepath << " on the ID map" << std::endl;
			returnValue = -1;
		}else {
			returnValue = iter->second;
		}
	}
	return returnValue;
}

int ResourceManager::addTexture(const char* filepath) {
	sf::Texture* graph1 = new sf::Texture();

	bool loaded = graph1->loadFromFile(filepath);

	if (!loaded) {
		std::cerr << "Error when loading image: " << filepath << std::endl;
		return -1;
	}else {
		mTexturesMap.insert(std::pair<std::string, sf::Texture*>(filepath, graph1));
		int returnValue = 0;
		if (mFirstFreeSlot == mTexturesVector.size()) {
			mTexturesVector.push_back(graph1);
			mFirstFreeSlot++;
			returnValue = mTexturesVector.size() - 1;
		}else {
			mTexturesVector[mFirstFreeSlot] = graph1;
			returnValue = mFirstFreeSlot;
			mFirstFreeSlot = updateFirstFreeSlot();
		}
		return returnValue;
	}
}


sf::Sprite* ResourceManager::getSpriteByID(int ID) {
	if (ID >= 0 && ID < mSpritesVector.size()) {
		return mSpritesVector[ID];
	}
	else {
		return NULL;
	}
}

sf::Texture* ResourceManager::getTextureByID(int ID) {
	if (ID >= 0 && ID < mTexturesVector.size()) {
		return mTexturesVector[ID];
	}else {
		return NULL;
	}
}

int ResourceManager::searchSprite(sf::Sprite* spr) {
	int size = mSpritesVector.size();
	for (int i = 0; i < size; i++) {
		if (mSpritesVector[i] == spr) {
			return i;
		}
	}
	return -1;
}

int ResourceManager::updateFirstFreeSlot() {
	int size = mTexturesVector.size(); 
	for (int i = 0; i < size; i++) {
		if (mTexturesVector[i] == NULL) {
			return i;
		}
	}
	return size;
}

unsigned int ResourceManager::getSpriteWidth(int ID) {
	if (ID >= 0 && ID < mSpritesVector.size()) {
		return mSpritesVector[ID]->getTexture()->getSize().x;
	}else {
		return 0;
	}
}
unsigned int ResourceManager::getSpriteHeight(int ID) {
	if (ID >= 0 && ID < mSpritesVector.size()) {
		return mSpritesVector[ID]->getTexture()->getSize().y;
	}else {
		return 0;
	}
}