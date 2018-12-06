// author Andrew Bashorum
// est time 3 hours

#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
/// default construcor
/// pass parameters fpr sfml window, setup m_exitGame
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Missile Command" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	setup();
	explosion();
}

/// <summary>
/// default destructor for game, nothing to release
/// </summary>
Game::~Game()
{
}


/// <summary>
/// game loop running at 60fps
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	m_window.draw(floor);
	m_window.draw(m_altitudeText);

	m_window.draw(base);
	m_window.draw(powerbar);


	if (click = true)
	{

		m_window.draw(m_line);
	}

	m_window.display();

	

}

void Game::processMouseEvents(sf::Event t_mouseEvent)
{
	sf::Vertex lineVertex{};
	sf::Vector2f t_mouseClick{ 0,0 };
	

	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button);
	{
		t_mouseClick = sf::Vector2f{(float) t_mouseEvent.mouseButton.x,(float) t_mouseEvent.mouseButton.y };

		 lineVertex = sf::Vertex{ sf::Vector2f{ t_basePoint } , sf::Color::Red };
		 lineVertex = sf::Vertex{ sf::Vector2f{t_mouseClick} , sf::Color::Black };
		 m_line.append(lineVertex);
		 click = true;
	}
}

void::Game::explosion()
{

}
/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_altitudeText.setFont(m_ArialBlackfont);
	m_altitudeText.setString("Altitude");
	m_altitudeText.setPosition(20.0f, 572.5f);
	m_altitudeText.setCharacterSize(25);
	m_altitudeText.setOutlineColor(sf::Color::White);
	m_altitudeText.setFillColor(sf::Color::White);

//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		// error...

	}
//	sf::Text text;
//	text.setFont(m_ArialBlackfont);
//	text.setCharacterSize(10);
//	text.setFillColor(sf::Color::White);
//	text.setPosition()

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}


void Game::setup()
{
	floor.setSize(sf::Vector2f{ 800, 30 });
	floor.setPosition(sf::Vector2f{ 0, 570 });
	floor.setFillColor(sf::Color::Green);

	base.setSize(sf::Vector2f{ 50, 50 });
	base.setPosition(sf::Vector2f{ 370, 520 });
	base.setFillColor(sf::Color::Yellow);

	powerbar.setSize(sf::Vector2f{ 400, 15 });
	powerbar.setPosition(sf::Vector2f{ powerbarX, 580 });
	powerbar.setFillColor(sf::Color::Red);
}
