<<<<<<< HEAD

=======
// Name: Andrew Bashorum
// Login: C00238900
// Date: 29 November 2018
// EST Time: 30 mins
// Time Taken: 10 mins
//---------------------------------------------------------------------------
// Miisile command one. This is a game where an asteroid falls.
// the player is tasked with destroying it before it reached earth 
// Lab 9 prob 1
>>>>>>> 1fc50eb92c90b6841170916cb0a5083cb549fc44

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "game.h"



/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	Game game;
	game.run();
	return 0;
}