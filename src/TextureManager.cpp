#include "TextureManager.hpp"
#include <stdexcept>

using namespace std;
using namespace sf;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::getInstance(void)
{
	static TextureManager instance;
	return instance;
}

TexturePtr TextureManager::empty()
{
	return make_shared<Texture>();
}

TexturePtr TextureManager::getTexture(std::string path, bool load)
{
	auto result = textures.find(path);

	if(result != textures.end())
	{
		return result->second;
	}

	if(load)
	{
		return this->load(path);
	}
	else
	{
		throw runtime_error("Texture " + path + " not loaded !");
	}
}

TexturePtr TextureManager::load(std::string path)
{
	if(isLoaded(path))
		throw runtime_error("Texture "+ path + " already loaded !");

	TexturePtr New = make_shared<sf::Texture>();

	if(!New->loadFromFile(path))
		throw runtime_error("Cannot load texture : " + path);

	return textures.insert(make_pair(path, New)).first->second;
}

bool TextureManager::isLoaded(std::string path)
{
	auto result = textures.find(path);
	return result != textures.end();
}
