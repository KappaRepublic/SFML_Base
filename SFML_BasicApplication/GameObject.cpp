#include "GameObject.h"

GameObject::GameObject()
{
	
}

void GameObject::init(float posX, float posY, const char * texName)
{
	position.x = posX;
	position.y = posY;

	// Load texture and apply to sprite
	if (!tex.loadFromFile(texName))
	{
		// Error...
	}

	sprite.setTexture(tex);

	// Update sprite position
	sprite.setPosition(position);
}

void GameObject::setTexture(const char * texName)
{
	if (!tex.loadFromFile(texName))
	{
		// Error...
	}

	sprite.setTexture(tex);
}

void GameObject::update(float dt)
{
	sprite.setPosition(position);
}

void GameObject::draw(sf::RenderWindow * win)
{
	win->draw(sprite);
}
