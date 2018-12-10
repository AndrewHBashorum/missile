// author Andrew Bashorum .com
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
	//setupFontAndText(); // load font 
	setupSprite(); // load texture
	setup();
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
		if (sf::Event::MouseButtonPressed == event.type)
		{
			processMouseEvents(event);
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
	

	m_window.draw(base);
	m_window.draw(powerbar);
	m_window.draw(m_altitudeText);



	
		m_window.draw(m_line);

	m_window.display();

	

}

void Game::processMouseEvents(sf::Event t_mouseEvent)
{
	sf::Vertex lineStart{};
	sf::Vertex lineEnd{};
	sf::Vector2f mouseClick{};

	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)
	{
		t_basePoint = sf::Vector2f{ 400 , 510 };
		lineStart = sf::Vertex{ t_basePoint, sf::Color::Green };
		m_line.append(lineStart);
		m_startClick = true;


		if (m_startClick == true && m_endClick == false)
		{
			mouseClick = sf::Vector2f{ static_cast<float>(t_mouseEvent.mouseButton.x),static_cast<float>(t_mouseEvent.mouseButton.y) };
			lineEnd = sf::Vertex{ mouseClick, sf::Color::Red };
			m_line.append(lineEnd);									 // finds mouse position on click 2
			m_endClick = true;
		}
		else if (m_startClick == true && m_endClick == true)
		{
			m_line.clear();
			m_startClick = false;
			m_endClick = false;
		}
	}
}


/// <summary>
/// load the font and setup the text message for screen
/// </summary>
//void Game::setupFontAndText();
//{
//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
//	{
//		std::cout << "problem loading arial black font" << std::endl;
//	}
//	m_altitudeText.setFont(m_ArialBlackfont);
//	m_altitudeText.setString("Altitude");
//	m_altitudeText.setPosition(20.0f, 572.5f);
//	m_altitudeText.setCharacterSize(25);
//	m_altitudeText.setOutlineColor(sf::Color::White);
//m_altitudeText.setFillColor(sf::Color::White);
//
//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
//	{
//		error..
//
//	}
///		text.setCharacterSize(10);
////			text.setFillColor(sf::Color::White);
////			text.setPosition()
////}



/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	//nhvh
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

float vectorLength(const sf::Vector2f t_vector)
{
	float sumOfSquares = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y);
	float length = sqrt(sumOfSquares);
	return length;
}

