#pragma once
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>

class GameObject
{
public:
	// Functtions
	GameObject();
	void init(float posX, float posY, const char* texName);
	void setTexture(const char* texName);
	void update(float dt);
	void draw(sf::RenderWindow* win);

	// Getters and Setters
	inline sf::Vector2f getPosition() { return position; };
	inline void setPosition(sf::Vector2f pos) { position = pos; };
private:
	// Attributes
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture tex;
};
