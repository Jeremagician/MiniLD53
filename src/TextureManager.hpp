#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

typedef std::shared_ptr<sf::Texture> TexturePtr;

class TextureManager
{
public:

	TexturePtr getTexture(std::string path, bool load = false);

	TexturePtr load(std::string path);

	bool isLoaded(std::string path);

	TexturePtr empty();

	static TextureManager& getInstance(void);
private:

	std::map<std::string, TexturePtr> textures;

	// Singleton
	TextureManager();
	~TextureManager();
};

#endif /* TEXTUREMANAGER_H_ */
