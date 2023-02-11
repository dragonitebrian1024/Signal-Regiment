#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "InputManager.h"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


static SDL_Renderer* renderer;
class Game {
public:
	Game();
	~Game();

	int seed;

	int timer;
	int entertimer;

	int whichpin[6];

	int page;

	SDL_Texture* titlescreen;
	SDL_Rect titlescreenRect;

	SDL_Texture* playtext;
	SDL_Rect playbutton;

	SDL_Texture* quittext;
	SDL_Rect quitbutton;

	SDL_Texture* EnterButton;
	SDL_Rect EnterButtonRect;
	bool entered;

	SDL_Texture* titlescreenText;
	SDL_Rect titlescreenTextRect;

	SDL_Rect Mouse, Mouse2;

	bool enterr;

	int level;
	int currentlevel;

	SDL_Rect table;
	SDL_Rect LightRadio;
	SDL_Rect Pinbox;

	SDL_Texture* level1reminder;
	SDL_Rect level1reminderRect;

	SDL_Texture* level2reminder;
	SDL_Rect level2reminderRect;

	SDL_Texture* level3reminder;
	SDL_Rect level3reminderRect;

	SDL_Texture* level4reminder;
	SDL_Rect level4reminderRect;

	bool exited;

	SDL_Texture* levelinstructions[10];
	SDL_Rect levelinstructionsRect[10];
	bool instructing;

	SDL_Rect timeleft;
	SDL_Rect BarBox;

	//not important just for looks
	SDL_Rect wire;

	SDL_Texture* lights[12];
	SDL_Rect lightsRect[12];

	bool spawned;
	
	int score[10];

	SDL_Texture* Pinholes[15];
	SDL_Rect PinholesRect[15];

	SDL_Texture* Pins[6];
	SDL_Rect PinsRect[6];

	SDL_Texture* lightsOff[12];

	SDL_Texture* level1Text;
	SDL_Rect level1Button;

	SDL_Texture* level2Text;
	SDL_Rect level2Button;

	SDL_Texture* level3Text;
	SDL_Rect level3Button;

	SDL_Texture* level4Text;
	SDL_Rect level4Button;

	int lightsOn[12];
	int combination;
	int combination2;

	int highscore[10];

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleevents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };

private:
	bool isRunning;
	bool lost;
	SDL_Window* window;
	InputManager* inputmanager;
};
