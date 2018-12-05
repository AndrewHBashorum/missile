// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();
	void setup();
	void explosion();
	void processMouseEvents(sf::Event t_mouseEvent);

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_altitudeText; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo

	sf::RectangleShape floor;
	sf::RectangleShape base;
	sf::RectangleShape powerbar;

	float powerbarX = 0.0f;
	bool m_exitGame; // control exiting game
	bool click = false;

	sf::VertexArray m_line{ sf::Lines };
	sf::Vector2i t_mouseClick{ 0 , 0 };
	sf::Vector2i t_endpoint{ 100,50 };

};

#endif // !GAME

