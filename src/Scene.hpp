#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.hpp>
#include "InputHandler.hpp"
#include <memory>

class Scene : public sf::Drawable
{
public:
	typedef std::shared_ptr<Scene> Ptr;

	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	InputHandler::Ptr getInputHandler(void);
    bool hasInputHandler(void);

protected:
	void setInputHandler(InputHandler::Ptr inputHandler);

private:
	InputHandler::Ptr inputHandler;
};

#endif /* SCENE_H_ */
