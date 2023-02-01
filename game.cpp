#include "game.h"
#include <iostream>
TTF_Font* font;
Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 50, 40, 233, 100);
			std::cout << "renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	TTF_Init();
	font = TTF_OpenFont("Arial.ttf", 12);
	inputmanager = InputManager::Instance();
	page = 0;
	Mouse.w = 25;
	Mouse.h = 25;
	titlescreenText = TextureManager::LoadText("Signal Regiment", renderer, font);
	titlescreenTextRect = { 200, 15, 900, 300 };

	playtext = TextureManager::LoadText("Play", renderer, font);
	playbutton = { 500, 400, 240, 150 };

	quittext = TextureManager::LoadText("Quit", renderer, font);
	quitbutton = { 500, 600, 240, 150 };

	level1Text = TextureManager::LoadText("Level 1", renderer, font);
	level1Button = { 100, 100, 140, 100 };

	titlescreen = TextureManager::LoadTexture("signal regiment title screen.png", renderer);
	titlescreenRect = { 0, 0, 1200, 800 };

	lights[0] = TextureManager::LoadTexture("led on.png", renderer);
	lights[1] = TextureManager::LoadTexture("led on.png", renderer);
	lights[2] = TextureManager::LoadTexture("led on.png", renderer);
	lights[3] = TextureManager::LoadTexture("led on.png", renderer);
	lights[4] = TextureManager::LoadTexture("led on.png", renderer);
	lights[5] = TextureManager::LoadTexture("led on.png", renderer);
	lights[6] = TextureManager::LoadTexture("led on.png", renderer);
	lights[7] = TextureManager::LoadTexture("led on.png", renderer);
	lights[8] = TextureManager::LoadTexture("led on.png", renderer);
	lights[9] = TextureManager::LoadTexture("led on.png", renderer);
	lights[10] = TextureManager::LoadTexture("led on.png", renderer);
	lights[11] = TextureManager::LoadTexture("led on.png", renderer);

	lightsOff[0] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[1] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[2] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[3] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[4] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[5] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[6] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[7] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[8] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[9] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[10] = TextureManager::LoadTexture("led off.png", renderer);
	lightsOff[11] = TextureManager::LoadTexture("led off.png", renderer);

	Pinholes[0] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[1] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[2] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[3] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[4] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[5] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[6] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[7] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[8] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[9] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[10] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[11] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[12] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[13] = TextureManager::LoadTexture("pinhole.png", renderer);
	Pinholes[14] = TextureManager::LoadTexture("pinhole.png", renderer);

	Pins[0] = TextureManager::LoadTexture("pin 1.png", renderer);
	Pins[1] = TextureManager::LoadTexture("pin 2.png", renderer);
	Pins[2] = TextureManager::LoadTexture("pin 3.png", renderer);
	Pins[3] = TextureManager::LoadTexture("pin 4.png", renderer);
	Pins[4] = TextureManager::LoadTexture("pin 5.png", renderer);
	Pins[5] = TextureManager::LoadTexture("pin 6.png", renderer);

	lightsOn[0] = 0;
	lightsOn[1] = 0;
	lightsOn[2] = 0;
	lightsOn[3] = 0;
	lightsOn[4] = 0;
	lightsOn[5] = 0;
	lightsOn[6] = 0;
	lightsOn[7] = 0;
	lightsOn[8] = 0;
	lightsOn[9] = 0;
	lightsOn[10] = 0;
	lightsOn[11] = 0;
	timer = 600;
	combination = 3;
	combination2 = 3;
	level = 1;
	currentlevel = 0;
	spawned = false;
}

void Game::handleevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		switch (event.button.button)
		{
		case SDL_BUTTON_LEFT:
			Mouse.x = event.motion.x;
			Mouse.y = event.motion.y;
		}
	default:
		break;
	}
}

void Game::update()
{
	SDL_bool Play = SDL_HasIntersection(&Mouse, &playbutton);
	SDL_bool Quit = SDL_HasIntersection(&Mouse, &quitbutton);
	SDL_bool Level1 = SDL_HasIntersection(&Mouse, &level1Button);
	inputmanager->Update();
	timer -= 1;
	entertimer -= 1;
	switch (page)
	{
	case 0:
		if (Play)
			page = 1;
		else if (Quit)
			isRunning = false;
		break;
	case 1:
		if (level >= 1 && Level1)
		{
			page = 2;
		}
		break;
	case 2:
		SDL_bool clickedPinhole0 = SDL_HasIntersection(&Mouse, &PinholesRect[0]);
		SDL_bool clickedPinhole1 = SDL_HasIntersection(&Mouse, &PinholesRect[1]);
		SDL_bool clickedPinhole2 = SDL_HasIntersection(&Mouse, &PinholesRect[2]);
		SDL_bool clickedPinhole3 = SDL_HasIntersection(&Mouse, &PinholesRect[3]);
		SDL_bool clickedPinhole4 = SDL_HasIntersection(&Mouse, &PinholesRect[4]);
		SDL_bool clickedPinhole5 = SDL_HasIntersection(&Mouse, &PinholesRect[5]);
		std::cout << timer << std::endl;
		std::cout << entertimer << std::endl;
		std::cout << combination << std::endl;
		std::cout << combination2 << std::endl;
		table = { 0, 790, 1400, 10 };
		Pinbox = { 500, 470, 500, 320 };
		LightRadio = { 50, 510, 300, 280 };
		//top row
		lightsRect[0] = { 75, 535, 20, 20 };
		lightsRect[1] = { 315, 535, 20, 20 };
		//bottom row
		lightsRect[2] = { 75, 735, 20, 20 };
		lightsRect[3] = { 315, 735, 20, 20 };
		if (timer <= 0 && spawned == false)
		{
			combination = rand() % 3;
			combination2 = rand() % 3;
			entertimer = 600;
			spawned = true;
		}
		if (combination == 1 && combination2 == 1)
		{
			lightsOn[0] = 1;
			lightsOn[1] = 0;
			lightsOn[2] = 1;
			lightsOn[3] = 0;
			if (whichpin[0] == 1 && whichpin[1] == 1)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				spawned = false;
				timer = 600;
				combination = 3;
				combination2 = 3;
			}
		}
		else if (combination == 2 && combination2 == 1)
		{
			lightsOn[0] = 0;
			lightsOn[1] = 1;
			lightsOn[2] = 1;
			lightsOn[3] = 0;
			if (whichpin[0] == 2 && whichpin[1] == 1)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				spawned = false;
				timer = 600;
				combination = 2;
				combination2 = 2;
			}
		}
		else if (combination == 1 && combination2 == 2)
		{
			lightsOn[0] = 1;
			lightsOn[1] = 0;
			lightsOn[2] = 0;
			lightsOn[3] = 1;
			if (whichpin[0] == 1 && whichpin[1] == 2)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				timer = 600;
				spawned = false;
				combination = 3;
				combination2 = 3;
			}
		}
		if (combination == 2 && combination2 == 2)
		{
			lightsOn[0] = 0;
			lightsOn[1] = 1;
			lightsOn[2] = 0;
			lightsOn[3] = 1;
			if (whichpin[0] == 2 && whichpin[1] == 2)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				timer = 600;
				spawned = false;
				combination = 3;
				combination2 = 3;
			}
		}
		else if (combination == 2 && combination2 == 2)
			entertimer = 690;

		if (clickedPinhole0)
			whichpin[0] = 0;
		else if (clickedPinhole1)
			whichpin[0] = 1;
		else if (clickedPinhole2)
			whichpin[0] = 2;
		else if (clickedPinhole3)
			whichpin[1] = 0;
		else if (clickedPinhole4)
			whichpin[1] = 1;
		else if (clickedPinhole5)
			whichpin[1] = 2;


		if (whichpin[0] == 0)
			PinsRect[0] = { 523, 493, 18, 18 };
		else if (whichpin[0] == 1)
			PinsRect[0] = { 723, 493, 18, 18 };
		else if (whichpin[0] == 2)
			PinsRect[0] = { 823, 493, 18, 18 };

		if (whichpin[1] == 0)
			PinsRect[1] = { 523, 750, 18, 18 };
		else if (whichpin[1] == 1)
			PinsRect[1] = { 723, 750, 18, 18 };
		else if (whichpin[1] == 2)
			PinsRect[1] = { 823, 750, 18, 18 };

		PinholesRect[0] = { 523, 493, 18, 18 };
		PinholesRect[1] = { 723, 493, 18, 18 };
		PinholesRect[2] = { 823, 493, 18, 18 };
		PinholesRect[3] = { 523, 750, 18, 18 };
		PinholesRect[4] = { 723, 750, 18, 18 };
		PinholesRect[5] = { 823, 750, 18, 18 };

		if (entertimer <= 0) {
			//lose
		}
		break;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	switch (page)
	{
	case 0:
		SDL_RenderCopy(renderer, titlescreen, NULL, &titlescreenRect);
		SDL_RenderCopy(renderer, titlescreenText, NULL, &titlescreenTextRect);
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
		SDL_RenderFillRect(renderer, &playbutton);
		SDL_RenderFillRect(renderer, &quitbutton);
		SDL_RenderCopy(renderer, playtext, NULL, &playbutton);
		SDL_RenderCopy(renderer, quittext, NULL, &quitbutton);
		break;
	case 1:
		if (level >= 1) {
			SDL_RenderCopy(renderer, titlescreen, NULL, &titlescreenRect);
			SDL_RenderFillRect(renderer, &level1Button);
			SDL_RenderCopy(renderer, level1Text, NULL, &level1Button);
		}
		break;
	case 2:
		SDL_SetRenderDrawColor(renderer, 64, 31, 0, 0);
		SDL_RenderFillRect(renderer, &table);
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 40);
		SDL_RenderFillRect(renderer, &LightRadio);
		SDL_SetRenderDrawColor(renderer, 45, 45, 45, 45);
		SDL_RenderFillRect(renderer, &Pinbox);
		SDL_SetRenderDrawColor(renderer, 156, 90, 60, 0);
		if (lightsOn[0] == 1)
			SDL_RenderCopy(renderer, lights[0], NULL, &lightsRect[0]);
		else
			SDL_RenderCopy(renderer, lightsOff[0], NULL, &lightsRect[0]);

		if (lightsOn[1] == 1)
			SDL_RenderCopy(renderer, lights[1], NULL, &lightsRect[1]);
		else
			SDL_RenderCopy(renderer, lightsOff[1], NULL, &lightsRect[1]);

		if (lightsOn[2] == 1)
			SDL_RenderCopy(renderer, lights[2], NULL, &lightsRect[2]);
		else
			SDL_RenderCopy(renderer, lightsOff[2], NULL, &lightsRect[2]);

		if (lightsOn[3] == 1)
			SDL_RenderCopy(renderer, lights[3], NULL, &lightsRect[3]);
		else
			SDL_RenderCopy(renderer, lightsOff[3], NULL, &lightsRect[3]);

		if (lightsOn[4] == 1)
			SDL_RenderCopy(renderer, lights[4], NULL, &lightsRect[4]);
		else
			SDL_RenderCopy(renderer, lightsOff[4], NULL, &lightsRect[4]);

		if (lightsOn[5] == 1)
			SDL_RenderCopy(renderer, lights[5], NULL, &lightsRect[5]);
		else
			SDL_RenderCopy(renderer, lightsOff[5], NULL, &lightsRect[5]);

		if (lightsOn[6] == 1)
			SDL_RenderCopy(renderer, lights[6], NULL, &lightsRect[6]);
		else
			SDL_RenderCopy(renderer, lightsOff[6], NULL, &lightsRect[6]);

		if (lightsOn[7] == 1)
			SDL_RenderCopy(renderer, lights[7], NULL, &lightsRect[7]);
		else
			SDL_RenderCopy(renderer, lightsOff[7], NULL, &lightsRect[7]);

		if (lightsOn[8] == 1)
			SDL_RenderCopy(renderer, lights[8], NULL, &lightsRect[8]);
		else
			SDL_RenderCopy(renderer, lightsOff[8], NULL, &lightsRect[8]);

		if (lightsOn[9] == 1)
			SDL_RenderCopy(renderer, lights[9], NULL, &lightsRect[9]);
		else
			SDL_RenderCopy(renderer, lightsOff[9], NULL, &lightsRect[9]);

		if (lightsOn[10] == 1)
			SDL_RenderCopy(renderer, lights[10], NULL, &lightsRect[10]);
		else
			SDL_RenderCopy(renderer, lightsOff[10], NULL, &lightsRect[10]);

		if (lightsOn[11] == 1)
			SDL_RenderCopy(renderer, lights[11], NULL, &lightsRect[11]);
		else
			SDL_RenderCopy(renderer, lightsOff[11], NULL, &lightsRect[11]);

		SDL_RenderCopy(renderer, Pinholes[0], NULL, &PinholesRect[0]);
		SDL_RenderCopy(renderer, Pinholes[1], NULL, &PinholesRect[1]);
		SDL_RenderCopy(renderer, Pinholes[2], NULL, &PinholesRect[2]);
		SDL_RenderCopy(renderer, Pinholes[3], NULL, &PinholesRect[3]);
		SDL_RenderCopy(renderer, Pinholes[4], NULL, &PinholesRect[4]);
		SDL_RenderCopy(renderer, Pinholes[5], NULL, &PinholesRect[5]);
		SDL_RenderCopy(renderer, Pins[0], NULL, &PinsRect[0]);
		SDL_RenderCopy(renderer, Pins[1], NULL, &PinsRect[1]);

		break;
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	InputManager::Release();
	inputmanager = NULL;
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	std::cout << "game cleaned :)" << std::endl;
}