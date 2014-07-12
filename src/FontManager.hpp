#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

typedef std::shared_ptr<sf::Font> FontPtr;

class FontManager
{
public:

	FontPtr getFont(std::string path, bool load = false);

	FontPtr load(std::string path);

	bool isLoaded(std::string path);

	// Return an empty font
	FontPtr empty(void);

	static FontManager& getInstance(void);

private:
	std::map<std::string, FontPtr> fonts;

	FontManager();
	~FontManager();
};

#endif /* FONTMANAGER_H_ */
