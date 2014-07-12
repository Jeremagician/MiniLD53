#include "FontManager.hpp"
#include <stdexcept>

using namespace sf;
using namespace std;

FontManager::FontManager()
{

}

FontManager::~FontManager()
{

}

FontManager& FontManager::getInstance(void)
{
	static FontManager instance; // thread safe since C++11
	return instance;
}

FontPtr FontManager::empty(void)
{
	return make_shared<Font>();
}

FontPtr FontManager::getFont(std::string path, bool load)
{
	auto result = fonts.find(path);
	if(result != fonts.end())
	{
		return result->second;
	}

	if(load)
	{
		return this->load(path);
	}
	else
	{
		throw runtime_error("Font '" + path +"' is not loaded");
	}
}

FontPtr FontManager::load(std::string path)
{
	if(isLoaded(path))
	{
		throw runtime_error("Font '" + path + "' already loaded");
	}

	FontPtr New = make_shared<Font>();

	if(!New->loadFromFile(path))
	{
		throw runtime_error("Cannot load font " + path);
	}

	return New;
}

bool FontManager::isLoaded(std::string path)
{
	auto result = fonts.find(path);
	return result != fonts.end();
}
