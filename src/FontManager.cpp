#include "FontManager.hpp"

using namespace sf;
using namespace std;

FontManager::FontManager()
	: emptyFont(new Font)
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

FontPtr FontManager::getFont(std::string name, bool load)
{
	auto result = fonts.find(name);
	if(result == fonts.end())
	{
		if(load)
		{
			FontPtr font = make_shared<Font>();
			if(!font->loadFromFile(name))
			{
				goto empty;
			}
			return fonts.insert(make_pair(name, font)).first->second;
		}
	empty:
		return emptyFont;
	}
	return result->second;
}
