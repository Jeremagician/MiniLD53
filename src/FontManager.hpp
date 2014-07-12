#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

typedef std::shared_ptr<sf::Font> FontPtr;

class FontManager
{
public:
	// Return font, if font is unknown
	// an empty font is returned
	// If load is set to true, font will be loaded
	FontPtr getFont(std::string name, bool load=false);

	static FontManager& getInstance(void);

private:
	std::map<std::string, FontPtr> fonts;
	FontPtr emptyFont;

	FontManager();
	~FontManager();
};

#endif /* FONTMANAGER_H_ */
