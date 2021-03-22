#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "includes.h"
#include <SFML/Graphics.hpp>

//! ResourceManager class
/*!
	Handles the load and management of the Textures in the game
*/
class ResourceManager {
	public:
		ResourceManager();
		~ResourceManager();

		static ResourceManager* getInstance();

		int getSpriteID(const char* filepath);
		sf::Sprite* getSpriteByID(int ID);
		unsigned int getSpriteWidth(int ID);
		unsigned int getSpriteHeight(int ID);

	private:
		int searchSprite(sf::Sprite* spr);
		int getTextureID(const char* filepath);
		int addTexture(const char* filepath);
		sf::Texture* getTextureByID(int ID);

		int updateFirstFreeSlot();

		static ResourceManager* instance;

		std::map<std::string, sf::Sprite*>	mSpritesMap;
		std::vector<sf::Sprite*>			mSpritesVector;
		std::map<std::string, sf::Texture*>	mTexturesMap;
		std::vector<sf::Texture*>			mTexturesVector;
		std::map<std::string, int>			mIDMap;

		int									mFirstFreeSlot;
};

#endif