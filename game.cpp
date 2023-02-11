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
	Mouse2.w = 25;
	Mouse2.h = 25;
	titlescreenText = TextureManager::LoadText("Signal Regiment", renderer, font);
	titlescreenTextRect = { 200, 15, 900, 300 };
	instructing = false;

	playtext = TextureManager::LoadText("Play", renderer, font);
	playbutton = { 500, 400, 240, 150 };

	quittext = TextureManager::LoadText("Quit", renderer, font);
	quitbutton = { 500, 600, 240, 150 };

	level1Text = TextureManager::LoadText("Level 1", renderer, font);
	level1Button = { 100, 100, 140, 100 };

	level2Text = TextureManager::LoadText("Level 2", renderer, font);
	level2Button = { 260, 100, 140, 100 };

	titlescreen = TextureManager::LoadTexture("signal regiment title screen.png", renderer);
	titlescreenRect = { 0, 0, 1200, 800 };

	level1reminder = TextureManager::LoadText("You can play level 2 now", renderer, font);
	level1reminderRect = { 300, 100, 700, 300 };

	level3reminder = TextureManager::LoadText("You can play level 4 now", renderer, font);
	level3reminderRect = { 300, 100, 700, 300 };

	level4reminder = TextureManager::LoadText("You can play level 5 now", renderer, font);
	level4reminderRect = { 300, 100, 700, 300 };

	levelinstructions[0] = TextureManager::LoadTexture("level 1 instructions.png", renderer);
	levelinstructionsRect[0] = {250, 50, 700, 700};

	level2reminder = TextureManager::LoadText("You can play level 3 now", renderer, font);
	level2reminderRect = { 300, 100, 700, 300 };

	levelinstructions[1] = TextureManager::LoadTexture("level 2 instructions.png", renderer);
	levelinstructionsRect[1] = { 250, 50, 700, 700 };

	levelinstructions[2] = TextureManager::LoadTexture("level 3 instructions.png", renderer);
	levelinstructionsRect[2] = { 250, 50, 700, 700 };

	levelinstructions[3] = TextureManager::LoadTexture("level 4 instructions.png", renderer);
	levelinstructionsRect[3] = { 250, 50, 700, 700 };

	level3Text = TextureManager::LoadText("Level 3", renderer, font);
	level3Button = { 420, 100, 140, 100 };

	level4Text = TextureManager::LoadText("Level 4", renderer, font);
	level4Button = { 580, 100, 140, 100 };



	EnterButton = TextureManager::LoadText("Enter", renderer, font);

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
	combination = 2;
	combination2 = 2;
	level = 1;
	currentlevel = 0;
	spawned = false;
	int x = 0;
	std::string string;
	std::ifstream file2("data2.txt");
	std::ifstream file("data.txt");
	while (std::getline(file, string))
	{
		std::cout << "time" << std::endl;
		if (string.empty())
			highscore[x] = 0;
		else
    		highscore[x] = std::stoi(string);
		std::cout << highscore[x] << std::endl;
		x++;
		if (x == 10)
			break;
	}
	while (std::getline(file2, string))
	{
		std::cout << "times" << std::endl;
		if (string.empty())
			level = 1;
		else 
    		level = std::stoi(string);
		std::cout << level << std::endl;
	}
	file2.close();
	file.close();
	if (level > 10 || level <= 0)
		level = 1;
	std::cout << enterr << std::endl;
	std::cout << exited << std::endl;
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
			Mouse2.x = 1234567;
			Mouse2.y = 1234567;
			break;
		case SDL_BUTTON_RIGHT:
			Mouse2.x = event.motion.x;
			Mouse2.y = event.motion.y;
			Mouse.x = 1234567;
			Mouse.y = 1234567;
			std::cout << "right click";
			break;
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
	SDL_bool Level2 = SDL_HasIntersection(&Mouse, &level2Button);
	SDL_bool Level3 = SDL_HasIntersection(&Mouse, &level3Button);
	SDL_bool Level4 = SDL_HasIntersection(&Mouse, &level4Button);
	SDL_bool clickedPinhole0 = SDL_HasIntersection(&Mouse, &PinholesRect[0]);
	SDL_bool clickedPinhole1 = SDL_HasIntersection(&Mouse, &PinholesRect[1]);
	SDL_bool clickedPinhole2 = SDL_HasIntersection(&Mouse, &PinholesRect[2]);
	SDL_bool clickedPinhole3 = SDL_HasIntersection(&Mouse, &PinholesRect[3]);
	SDL_bool clickedPinhole4 = SDL_HasIntersection(&Mouse, &PinholesRect[4]);
	SDL_bool clickedPinhole5 = SDL_HasIntersection(&Mouse, &PinholesRect[5]);
	SDL_bool clickedPinhole6 = SDL_HasIntersection(&Mouse, &PinholesRect[6]);
	SDL_bool clickedPinhole7 = SDL_HasIntersection(&Mouse, &PinholesRect[7]);
	SDL_bool clickedPinhole8 = SDL_HasIntersection(&Mouse, &PinholesRect[8]);
	SDL_bool clickedPinhole12 = SDL_HasIntersection(&Mouse2, &PinholesRect[1]);
	SDL_bool clickedPinhole22 = SDL_HasIntersection(&Mouse2, &PinholesRect[2]);
	SDL_bool clickedPinhole32 = SDL_HasIntersection(&Mouse2, &PinholesRect[3]);
	SDL_bool clickedPinhole42 = SDL_HasIntersection(&Mouse2, &PinholesRect[4]);
	SDL_bool clickedPinhole52 = SDL_HasIntersection(&Mouse2, &PinholesRect[5]);
	SDL_bool clickedPinhole62 = SDL_HasIntersection(&Mouse2, &PinholesRect[6]);
	SDL_bool clickedPinhole72 = SDL_HasIntersection(&Mouse2, &PinholesRect[7]);
	SDL_bool clickedPinhole82 = SDL_HasIntersection(&Mouse2, &PinholesRect[8]);
	SDL_bool clickedPinhole92 = SDL_HasIntersection(&Mouse2, &PinholesRect[9]);
	SDL_bool enter = SDL_HasIntersection(&Mouse, &EnterButtonRect);
	inputmanager->Update();
	timer -= 1;
	if (highscore[0] >= 500)
	{
		level = 2;
	}
	if (highscore[1] >= 600)
	{
		level = 3;
	}
	if (highscore[2] >= 600)
	{
		level = 4;
	}
	if (highscore[3] >= 600)
	{
		level = 5;
	}

	switch (page)
	{
	case 0:
	//title screen
		if (Play)
			page = 1;
		else if (Quit)
			isRunning = false;
		break;
	//level select
	case 1:
		timer = 600;
		exited = true;
		enterr = false;
		if (level >= 1 && Level1)
		{
			exited = false;
			page = 2;
		}
		if (level >= 2 && Level2)
		{
			exited = false;
			page = 3;
		}
		if (level >= 3 && Level3)
		{
			exited = false;
			page = 4;
		}
		if (level >= 4 && Level4)
		{
			exited = false;
			page = 5;
		}
		break;
    //level 1
	case 2:
		if (enterr == false)
		{
			exited = false;
			timer = 600;
			score[0] = 0;
			whichpin[0] = 0;
			whichpin[1] = 0;
			lightsOn[0] = 2;
			lightsOn[1] = 2;
			lightsOn[2] = 2;
			lightsOn[3] = 2;
			combination = 2;
			combination2 = 2;
			entertimer = 600;
			spawned = false;
			exited = false;
			enterr = true;
		}
		BarBox = { 1050, 65, 130, 650 };
		timeleft = { 1080, 100, 70, entertimer};

		if (inputmanager->KeyDown(SDL_SCANCODE_SPACE))
			instructing = true;
		else
			instructing = false;

		if (inputmanager->KeyDown(SDL_SCANCODE_ESCAPE)) {
			Mouse.x = 1234567;
			page = 1;
			exited = true;
		}

		if (exited == true)
			page = 1;

		if (score[0] >= highscore[0])
			highscore[0] = score[0];
		std::cout << "enterr = " << enterr << std::endl;
		std::cout << "exited = " << exited << std::endl;
		std::cout << combination << std::endl;
		std::cout << combination2 << std::endl;
		std::cout << page << std::endl;
		table = { 0, 790, 1400, 10 };
		Pinbox = { 500, 470, 500, 320 };
		LightRadio = { 50, 510, 300, 280 };
		wire = { 0, 780, 50, 10 };
		//top row
		lightsRect[0] = { 75, 535, 20, 20 };
		lightsRect[1] = { 315, 535, 20, 20 };
		//bottom row
		lightsRect[2] = { 75, 735, 20, 20 };
		lightsRect[3] = { 315, 735, 20, 20 };

		EnterButtonRect = { 750, 600, 200, 120 };
		if (timer <= 0 && spawned == false)
		{
			combination = rand() % 2;
			combination2 = rand() % 2;
			entertimer = 600;
			spawned = true;
		}
		if(spawned == true)
			entertimer -= 1;
		if (combination == 0 && combination2 == 0)
		{
			lightsOn[0] = 1;
			lightsOn[1] = 0;
			lightsOn[2] = 1;
			lightsOn[3] = 0;
			if (whichpin[0] == 1 && whichpin[1] == 1 && entered == true)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				spawned = false;
				score[0] += 100;
				timer = 600;
				entered = false;
				combination = 2;
				combination2 = 2;
			}
			else
				entered = false;
		}
		else if (combination == 1 && combination2 == 0)
		{
			lightsOn[0] = 0;
			lightsOn[1] = 1;
			lightsOn[2] = 1;
			lightsOn[3] = 0;
			if (whichpin[0] == 2 && whichpin[1] == 1 && entered == true)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				spawned = false;
				entered = false;
				timer = 600;
				score[0] += 100;
				combination = 2;
				combination2 = 2;
			}
			else
				entered = false;
		}
		else if (combination == 0 && combination2 == 1)
		{
			lightsOn[0] = 1;
			lightsOn[1] = 0;
			lightsOn[2] = 0;
			lightsOn[3] = 1;
			if (whichpin[0] == 1 && whichpin[1] == 2 && entered == true)
			{
				Mouse.x = 12345;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				whichpin[0] = 0;
				score[0] += 100;
				whichpin[1] = 0;
				timer = 600;
				spawned = false;
				entered = false;
				combination = 2;
				combination2 = 2;
			}
			else
				entered = false;
		}
		if (combination == 1 && combination2 == 1)
		{
			lightsOn[0] = 0;
			lightsOn[1] = 1;
			lightsOn[2] = 0;
			lightsOn[3] = 1;
			if (whichpin[0] == 2 && whichpin[1] == 2 && entered == true)
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
				entered = false;
				combination = 2;
				combination2 = 2;
				score[0] += 100;
			}
			else
				entered = false;
		}
		else if (combination == 2 && combination2 == 2)
			entertimer = 600;

		if (enter)
		{
			entered = true;
		}

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
			seed += 1;
			exited = true;
		}
		break;
		//level 2
		case 3:
			if (enterr == false)
			{
				exited = false;
				timer = 600;
				score[1] = 0;
				whichpin[0] = 0;
				whichpin[1] = 0;
				whichpin[2] = 0;
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				combination = 3;
				combination2 = 3;
				entertimer = 700;
				spawned = false;
				enterr = true;
			}
			BarBox = { 1050, 15, 130, 700 };
			timeleft = { 1080, 60, 70, entertimer };

			if (inputmanager->KeyDown(SDL_SCANCODE_SPACE))
				instructing = true;
			else
				instructing = false;

			if (inputmanager->KeyDown(SDL_SCANCODE_ESCAPE)) {
				Mouse.x = 12345;
				exited = true;
				page = 1;
			}

			if (exited == true)
				page = 1;

			if (score[1] >= highscore[1])
				highscore[1] = score[1];
			std::cout << "enterr = " << enterr << std::endl;
			std::cout << "exited = " << exited << std::endl;
			std::cout << combination << std::endl;
			std::cout << combination2 << std::endl;
			std::cout << page << std::endl;
			table = { 0, 790, 1400, 10 };
			Pinbox = { 500, 470, 500, 320 };
			LightRadio = { 50, 510, 300, 280 };
			wire = { 0, 780, 50, 10 };
			//top row
			lightsRect[0] = { 75, 535, 20, 20 };
			lightsRect[1] = { 215, 535, 20, 20 };
			lightsRect[2] = { 315, 535, 20, 20 };
			//bottom row
			lightsRect[3] = { 75, 735, 20, 20 };
			lightsRect[4] = { 315, 735, 20, 20 };

			EnterButtonRect = { 750, 600, 200, 120 };
			if (timer <= 0 && spawned == false)
			{
				combination = rand() % 3;
				combination2 = rand() % 3;
				entertimer = 700;
				spawned = true;
			}
			if (spawned == true)
				entertimer -= 1;

			if (combination == 0 && combination2 == 0)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 1;
				if (whichpin[0] == 1 && whichpin[2] == 3 && whichpin[1] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 0 && combination2 == 1)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				if (whichpin[0] == 1 && whichpin[2] == 3 && whichpin[1] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 0 && combination2 == 2)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				if (whichpin[0] == 1 && whichpin[2] == 3 && whichpin[1] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 1 && combination2 == 0)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 1;
				if (whichpin[0] == 3 && whichpin[2] == 1 && whichpin[1] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 2 && combination2 == 0)
			{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 1;
				if (whichpin[0] == 2 && whichpin[2] == 3 && whichpin[1] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 1 && combination2 == 1)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				if (whichpin[0] == 3 && whichpin[2] == 1 && whichpin[1] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 1 && combination2 == 2)
			{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 1;

				if (whichpin[0] == 3 && whichpin[2] == 1 && whichpin[1] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 2 && combination2 == 1)
			{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 0;

				if (whichpin[0] == 2 && whichpin[2] == 3 && whichpin[1] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					score[1] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
				}
				else
					entered = false;
			}
			else if (combination == 2 && combination2 == 2)
			{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 1;
				lightsOn[5] = 0;
				if (whichpin[0] == 2 && whichpin[2] == 3 && whichpin[1] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					spawned = false;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 3;
					score[1] += 100;
				}
				else
					entered = false;
			}
			else if (combination == 3 && combination2 == 3)
				entertimer = 600;

			if (enter)
			{
				entered = true;
			}
			if (clickedPinhole0)
				whichpin[0] = 0;
			else if (clickedPinhole2 && whichpin[2] != 1)
				whichpin[0] = 1;
			else if (clickedPinhole3 && whichpin[2] != 2)
				whichpin[0] = 2;
			else if (clickedPinhole4 && whichpin[2] != 3)
				whichpin[0] = 3;
			else if (clickedPinhole5)
				whichpin[1] = 0;
			else if (clickedPinhole6)
				whichpin[1] = 1;
			else if (clickedPinhole7)
				whichpin[1] = 2;
			else if (clickedPinhole8)
				whichpin[1] = 3;
			else if (clickedPinhole12)
				whichpin[2] = 0;
			else if (clickedPinhole22 && whichpin[0] != 1)
				whichpin[2] = 1;
			else if (clickedPinhole32 && whichpin[0] != 2)
				whichpin[2] = 2;
			else if (clickedPinhole42 && whichpin[0] != 3)
				whichpin[2] = 3;


			if (whichpin[0] == 0)
				PinsRect[0] = { 523, 493, 18, 18 };
			else if (whichpin[0] == 1)
				PinsRect[0] = { 723, 493, 18, 18 };
			else if (whichpin[0] == 2)
				PinsRect[0] = { 773, 493, 18, 18 };
			else if (whichpin[0] == 3)
				PinsRect[0] = { 823, 493, 18, 18 };

			if (whichpin[2] == 0)
				PinsRect[2] = { 523, 525, 18, 18 };
			else if (whichpin[2] == 1)
				PinsRect[2] = { 723, 493, 18, 18 };
			else if (whichpin[2] == 2)
				PinsRect[2] = { 773, 493, 18, 18 };
			else if (whichpin[2] == 3)
				PinsRect[2] = { 823, 493, 18, 18 };

			if (whichpin[1] == 0)
				PinsRect[1] = { 523, 750, 18, 18 };
			else if (whichpin[1] == 1)
				PinsRect[1] = { 723, 750, 18, 18 };
			else if (whichpin[1] == 2)
				PinsRect[1] = { 773, 750, 18, 18 };
			else if (whichpin[1] == 3)
				PinsRect[1] = { 823, 750, 18, 18 };

			PinholesRect[0] = { 523, 493, 18, 18 };
			PinholesRect[1] = { 523, 525, 18, 18 };
			PinholesRect[2] = { 723, 493, 18, 18 };
			PinholesRect[3] = { 773, 493, 18, 18 };
			PinholesRect[4] = { 823, 493, 18, 18 };
			PinholesRect[5] = { 523, 750, 18, 18 };
			PinholesRect[6] = { 723, 750, 18, 18 };
			PinholesRect[7] = { 773, 750, 18, 18 };
			PinholesRect[8] = { 823, 750, 18, 18 };

			if (entertimer <= 0) {
				//lose
				seed += 1;
				page = 1;
				exited = true;
			}
			break;
			//level 3
			case 4:
				page = 4;
				if (enterr == false)
				{
					exited = false;
					timer = 600;
					score[2] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					lightsOn[0] = 2;
					lightsOn[1] = 2;
					lightsOn[2] = 2;
					lightsOn[3] = 2;
					lightsOn[4] = 2;
					lightsOn[5] = 2;
					combination = 3;
					combination2 = 4;
					entertimer = 600;
					spawned = false;
					enterr = true;
				}
				BarBox = { 1050, 65, 130, 650 };
				timeleft = { 1080, 100, 70, entertimer };

				if (inputmanager->KeyDown(SDL_SCANCODE_SPACE))
					instructing = true;
				else
					instructing = false;

				if (inputmanager->KeyDown(SDL_SCANCODE_ESCAPE)) {
					Mouse.x = 12345;
					exited = true;
					page = 1;
				}

				if (exited == true)
					page = 1;

				if (score[2] >= highscore[2])
					highscore[2] = score[2];
				std::cout << "enterr = " << enterr << std::endl;
				std::cout << "exited = " << exited << std::endl;
				std::cout << combination << std::endl;
				std::cout << combination2 << std::endl;
				std::cout << page << std::endl;
				table = { 0, 790, 1400, 10 };
				Pinbox = { 500, 470, 500, 320 };
				LightRadio = { 50, 510, 300, 280 };
				wire = { 0, 780, 50, 10 };
				//top row
				lightsRect[0] = { 75, 535, 20, 20 };
				lightsRect[1] = { 215, 535, 20, 20 };
				lightsRect[2] = { 315, 535, 20, 20 };
				//bottom row
				lightsRect[3] = { 75, 735, 20, 20 };
				lightsRect[4] = { 215, 735, 20, 20 };
				lightsRect[5] = { 315, 735, 20, 20 };

				EnterButtonRect = { 750, 600, 200, 120 };
				if (timer <= 0 && spawned == false)
				{
					combination = rand() % 3;
					combination2 = rand() % 4;
					entertimer = 600;
					spawned = true;
				}
				if (combination == 0 && combination2 == 0)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 1;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					if (whichpin[0] == 1 && whichpin[1] == 1 && whichpin[3] == 2 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[2] += 100;
						timer = 600;
						entered = false;
						combination = 3;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 0 && combination2 == 1)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 1;
					lightsOn[4] = 0;
					lightsOn[5] = 1;
					if (whichpin[0] == 1 && whichpin[1] == 3 && whichpin[3] == 0 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[2] += 100;
						timer = 600;
						entered = false;
						combination = 3;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 0 && combination2 == 2)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 0;
					if (whichpin[0] == 1 && whichpin[1] == 2 && whichpin[3] == 1 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[2] += 100;
						timer = 600;
						entered = false;
						combination = 3;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 0 && combination2 == 3)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					if (whichpin[0] == 1 && whichpin[1] == 2 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[2] += 100;
						timer = 600;
						entered = false;
						combination = 3;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 1 && combination2 == 0)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				if (whichpin[0] == 2 && whichpin[1] == 1 && whichpin[3] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 0)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				if (whichpin[0] == 3 && whichpin[1] == 1 && whichpin[3] == 2 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 1 && combination2 == 1)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 1;
				if (whichpin[0] == 2 && whichpin[1] == 3 && whichpin[3] == 0 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 1)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 3 && whichpin[3] == 0 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 1 && combination2 == 2)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 0;
				if (whichpin[0] == 2 && whichpin[1] == 2 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 1 && combination2 == 3)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 1;
				if (whichpin[0] == 2 && whichpin[1] == 2 && whichpin[3] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 2)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 0;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 3)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[3] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[2] += 100;
					timer = 600;
					entered = false;
					combination = 3;
					combination2 = 4;
				}
				else
					entered = false;
				}


				if (spawned == true)
					entertimer -= 1;
				

				if (enter)
				{
					entered = true;
				}

				if (clickedPinhole0)
					whichpin[0] = 0;
				else if (clickedPinhole2)
					whichpin[0] = 1;
				else if (clickedPinhole3)
					whichpin[0] = 2;
				else if (clickedPinhole4)
					whichpin[0] = 3;
				else if (clickedPinhole5)
					whichpin[1] = 0;
				else if (clickedPinhole6)
					whichpin[1] = 1;
				else if (clickedPinhole7)
					whichpin[1] = 2;
				else if (clickedPinhole8)
					whichpin[1] = 3;
				else if (clickedPinhole12)
					whichpin[3] = 0;
				else if (clickedPinhole62)
					whichpin[3] = 1;
				else if (clickedPinhole72)
					whichpin[3] = 2;
				else if (clickedPinhole82)
					whichpin[3] = 3;


				if (whichpin[0] == 0)
					PinsRect[0] = { 523, 493, 18, 18 };
				else if (whichpin[0] == 1)
					PinsRect[0] = { 723, 493, 18, 18 };
				else if (whichpin[0] == 2)
					PinsRect[0] = { 773, 493, 18, 18 };
				else if (whichpin[0] == 3)
					PinsRect[0] = { 823, 493, 18, 18 };

				if (whichpin[1] == 0)
					PinsRect[1] = { 523, 750, 18, 18 };
				else if (whichpin[1] == 1)
					PinsRect[1] = { 723, 750, 18, 18 };
				else if (whichpin[1] == 2)
					PinsRect[1] = { 773, 750, 18, 18 };
				else if (whichpin[1] == 3)
					PinsRect[1] = { 823, 750, 18, 18 };

				if (whichpin[3] == 0)
					PinsRect[3] = { 523, 773, 18, 18 };
				else if (whichpin[3] == 1)
					PinsRect[3] = { 723, 750, 18, 18 };
				else if (whichpin[3] == 2)
					PinsRect[3] = { 773, 750, 18, 18 };
				else if (whichpin[3] == 3)
					PinsRect[3] = { 823, 750, 18, 18 };

				PinholesRect[0] = { 523, 493, 18, 18 };
				PinholesRect[1] = { 523, 773, 18, 18 };
				PinholesRect[2] = { 723, 493, 18, 18 };
				PinholesRect[3] = { 773, 493, 18, 18 };
				PinholesRect[4] = { 823, 493, 18, 18 };
				PinholesRect[5] = { 523, 750, 18, 18 };
				PinholesRect[6] = { 723, 750, 18, 18 };
				PinholesRect[7] = { 773, 750, 18, 18 };
				PinholesRect[8] = { 823, 750, 18, 18 };

				if (entertimer <= 0) {
					//lose
					seed += 1;
					exited = true;
				}
				break;
				//level 4
			case 5:
				page = 5;
				if (enterr == false)
				{
					exited = false;
					timer = 600;
					score[3] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					lightsOn[0] = 2;
					lightsOn[1] = 2;
					lightsOn[2] = 2;
					lightsOn[3] = 2;
					lightsOn[4] = 2;
					lightsOn[5] = 2;
					lightsOn[6] = 2;
					combination = 4;
					combination2 = 4;
					entertimer = 700;
					spawned = false;
					enterr = true;
				}
				BarBox = { 1050, 15, 130, 700 };
				timeleft = { 1080, 60, 70, entertimer };

				if (inputmanager->KeyDown(SDL_SCANCODE_SPACE))
					instructing = true;
				else
					instructing = false;

				if (inputmanager->KeyDown(SDL_SCANCODE_ESCAPE)) {
					Mouse.x = 12345;
					exited = true;
					page = 1;
				}

				if (exited == true)
					page = 1;

				if (score[3] >= highscore[3])
					highscore[3] = score[3];
				std::cout << "enterr = " << enterr << std::endl;
				std::cout << "exited = " << exited << std::endl;
				std::cout << combination << std::endl;
				std::cout << combination2 << std::endl;
				std::cout << page << std::endl;
				table = { 0, 790, 1400, 10 };
				Pinbox = { 500, 470, 500, 320 };
				LightRadio = { 50, 510, 300, 280 };
				wire = { 0, 780, 50, 10 };
				//top row
				lightsRect[0] = { 75, 535, 20, 20 };
				lightsRect[1] = { 150, 535, 20, 20 };
				lightsRect[2] = { 215, 535, 20, 20 };
				lightsRect[3] = { 315, 535, 20, 20 };
				//bottom row
				lightsRect[4] = { 75, 735, 20, 20 };
				lightsRect[5] = { 215, 735, 20, 20 };
				lightsRect[6] = { 315, 735, 20, 20 };

				EnterButtonRect = { 750, 600, 200, 120 };
				if (timer <= 0 && spawned == false)
				{
					combination = rand() % 4;
					combination2 = rand() % 4;
					entertimer = 700;
					spawned = true;
				}

				if (combination == 0 && combination2 == 0)
				{
					lightsOn[0] = 0;
					lightsOn[1] = 1;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					lightsOn[6] = 0;
					if (whichpin[0] == 1 && whichpin[1] == 1 && whichpin[2] == 3 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 1 && combination2 == 0)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 1;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					lightsOn[6] = 0;
					if (whichpin[0] == 2 && whichpin[1] == 1 && whichpin[2] == 1 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 2 && combination2 == 0)
				{
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 1;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					lightsOn[6] = 0;
					if (whichpin[0] == 3 && whichpin[1] == 1 && whichpin[2] == 2 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 3 && combination2 == 0)
				{
					lightsOn[0] = 1;
					lightsOn[1] = 0;
					lightsOn[2] = 1;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					lightsOn[6] = 0;
					if (whichpin[0] == 3 && whichpin[1] == 1 && whichpin[2] == 0 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 0 && combination2 == 1)
				{
					lightsOn[0] = 0;
					lightsOn[1] = 1;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 1;
					lightsOn[5] = 1;
					lightsOn[6] = 1;
					if (whichpin[0] == 1 && whichpin[1] == 3 && whichpin[2] == 3 && whichpin[3] == 0 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 0 && combination2 == 2)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 1;
				lightsOn[2] = 0;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				lightsOn[6] = 1;
				if (whichpin[0] == 1 && whichpin[1] == 2 && whichpin[2] == 3 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 0 && combination2 == 3)
				{
					lightsOn[0] = 0;
					lightsOn[1] = 1;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 1;
					lightsOn[6] = 1;
					if (whichpin[0] == 1 && whichpin[1] == 2 && whichpin[2] == 3 && whichpin[3] == 3 && entered == true)
					{
						Mouse.x = 12345;
						Mouse2.x = 12345;
						lightsOn[0] = 0;
						lightsOn[1] = 0;
						lightsOn[2] = 0;
						lightsOn[3] = 0;
						lightsOn[4] = 0;
						lightsOn[5] = 0;
						lightsOn[6] = 0;
						whichpin[0] = 0;
						whichpin[1] = 0;
						whichpin[2] = 0;
						whichpin[3] = 0;
						spawned = false;
						score[3] += 100;
						timer = 600;
						entered = false;
						combination = 4;
						combination2 = 4;
					}
					else
						entered = false;
				}
				else if (combination == 1 && combination2 == 1)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 1;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 2 && whichpin[1] == 3 && whichpin[2] == 1 && whichpin[3] == 0 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 1 && combination2 == 2)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				lightsOn[6] = 1;
				if (whichpin[0] == 2 && whichpin[1] == 2 && whichpin[2] == 1 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 1 && combination2 == 3)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 0;
				lightsOn[3] = 1;
				lightsOn[4] = 0;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 2 && whichpin[1] == 2 && whichpin[2] == 1 && whichpin[3] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 1)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 3 && whichpin[2] == 2 && whichpin[3] == 0 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 2)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[2] == 2 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 2 && combination2 == 3)
				{
				lightsOn[0] = 0;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[2] == 2 && whichpin[3] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 3 && combination2 == 1)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 1;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 3 && whichpin[2] == 0 && whichpin[3] == 0 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 3 && combination2 == 2)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 0;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[2] == 0 && whichpin[3] == 1 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}
				else if (combination == 3 && combination2 == 3)
				{
				lightsOn[0] = 1;
				lightsOn[1] = 0;
				lightsOn[2] = 1;
				lightsOn[3] = 0;
				lightsOn[4] = 0;
				lightsOn[5] = 1;
				lightsOn[6] = 1;
				if (whichpin[0] == 3 && whichpin[1] == 2 && whichpin[2] == 0 && whichpin[3] == 3 && entered == true)
				{
					Mouse.x = 12345;
					Mouse2.x = 12345;
					lightsOn[0] = 0;
					lightsOn[1] = 0;
					lightsOn[2] = 0;
					lightsOn[3] = 0;
					lightsOn[4] = 0;
					lightsOn[5] = 0;
					lightsOn[6] = 0;
					whichpin[0] = 0;
					whichpin[1] = 0;
					whichpin[2] = 0;
					whichpin[3] = 0;
					spawned = false;
					score[3] += 100;
					timer = 600;
					entered = false;
					combination = 4;
					combination2 = 4;
				}
				else
					entered = false;
				}

				if (spawned == true)
					entertimer -= 1;


				if (enter)
				{
					entered = true;
				}

				if (clickedPinhole0)
					whichpin[0] = 0;
				else if (clickedPinhole2)
					whichpin[0] = 1;
				else if (clickedPinhole3)
					whichpin[0] = 2;
				else if (clickedPinhole4)
					whichpin[0] = 3;
				else if (clickedPinhole5)
					whichpin[1] = 0;
				else if (clickedPinhole6)
					whichpin[1] = 1;
				else if (clickedPinhole7)
					whichpin[1] = 2;
				else if (clickedPinhole8)
					whichpin[1] = 3;
				else if (clickedPinhole12)
					whichpin[3] = 0;
				else if (clickedPinhole62)
					whichpin[3] = 1;
				else if (clickedPinhole72)
					whichpin[3] = 2;
				else if (clickedPinhole82)
					whichpin[3] = 3;
				else if (clickedPinhole92)
					whichpin[2] = 0;
				else if (clickedPinhole22)
					whichpin[2] = 1;
				else if (clickedPinhole32)
					whichpin[2] = 2;
				else if (clickedPinhole42)
					whichpin[2] = 3;

				if (whichpin[0] == 0)
					PinsRect[0] = { 523, 493, 18, 18 };
				else if (whichpin[0] == 1 && PinsRect[2].x != 723)
					PinsRect[0] = { 723, 493, 18, 18 };
				else if (whichpin[0] == 2 && PinsRect[2].x != 773)
					PinsRect[0] = { 773, 493, 18, 18 };
				else if (whichpin[0] == 3 && PinsRect[2].x != 823)
					PinsRect[0] = { 823, 493, 18, 18 };

				if (whichpin[1] == 0)
					PinsRect[1] = { 523, 750, 18, 18 };
				else if (whichpin[1] == 1 && PinsRect[3].x != 723)
					PinsRect[1] = { 723, 750, 18, 18 };
				else if (whichpin[1] == 2 && PinsRect[3].x != 773)
					PinsRect[1] = { 773, 750, 18, 18 };
				else if (whichpin[1] == 3 && PinsRect[3].x != 823)
					PinsRect[1] = { 823, 750, 18, 18 };

				if (whichpin[2] == 0)
					PinsRect[2] = { 523, 516, 18, 18 };
				else if (whichpin[2] == 1 && PinsRect[0].x != 723)
					PinsRect[2] = { 723, 493, 18, 18 };
				else if (whichpin[2] == 2 && PinsRect[0].x != 773)
					PinsRect[2] = { 773, 493, 18, 18 };
				else if (whichpin[2] == 3 && PinsRect[0].x != 823)
					PinsRect[2] = { 823, 493, 18, 18 };

				if (whichpin[3] == 0)
					PinsRect[3] = { 523, 773, 18, 18 };
				else if (whichpin[3] == 1 && PinsRect[1].x != 723)
					PinsRect[3] = { 723, 750, 18, 18 };
				else if (whichpin[3] == 2 && PinsRect[1].x != 773)
					PinsRect[3] = { 773, 750, 18, 18 };
				else if (whichpin[3] == 3 && PinsRect[1].x != 823)
					PinsRect[3] = { 823, 750, 18, 18 };

				PinholesRect[0] = { 523, 493, 18, 18 };
				PinholesRect[1] = { 523, 773, 18, 18 };
				PinholesRect[2] = { 723, 493, 18, 18 };
				PinholesRect[3] = { 773, 493, 18, 18 };
				PinholesRect[4] = { 823, 493, 18, 18 };
				PinholesRect[5] = { 523, 750, 18, 18 };
				PinholesRect[6] = { 723, 750, 18, 18 };
				PinholesRect[7] = { 773, 750, 18, 18 };
				PinholesRect[8] = { 823, 750, 18, 18 };
				PinholesRect[9] = { 523, 516, 18, 18 };

				if (entertimer <= 0) {
					//lose
					seed += 1;
					exited = true;
				}
				break;
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	switch (page)
	{
	//title screen
	case 0:
		SDL_RenderCopy(renderer, titlescreen, NULL, &titlescreenRect);
		SDL_RenderCopy(renderer, titlescreenText, NULL, &titlescreenTextRect);
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
		SDL_RenderFillRect(renderer, &playbutton);
		SDL_RenderFillRect(renderer, &quitbutton);
		SDL_RenderCopy(renderer, playtext, NULL, &playbutton);
		SDL_RenderCopy(renderer, quittext, NULL, &quitbutton);
		break;
	//level select
	case 1:
		SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
		if (level >= 1) {
			SDL_RenderCopy(renderer, titlescreen, NULL, &titlescreenRect);
			SDL_RenderFillRect(renderer, &level1Button);
			SDL_RenderCopy(renderer, level1Text, NULL, &level1Button);
		}
		if (level >= 2) {
			SDL_RenderFillRect(renderer, &level2Button);
			SDL_RenderCopy(renderer, level2Text, NULL, &level2Button);
		}
		if (level >= 3) {
			SDL_RenderFillRect(renderer, &level3Button);
			SDL_RenderCopy(renderer, level3Text, NULL, &level3Button);
		}
		if (level >= 4) {
			SDL_RenderFillRect(renderer, &level4Button);
			SDL_RenderCopy(renderer, level4Text, NULL, &level4Button);
		}
		break;
	//level 1
	case 2:
		SDL_SetRenderDrawColor(renderer, 64, 31, 0, 0);
		SDL_RenderFillRect(renderer, &table);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &wire);
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 40);
		SDL_RenderFillRect(renderer, &LightRadio);
		SDL_RenderFillRect(renderer, &EnterButtonRect);
		SDL_SetRenderDrawColor(renderer, 65, 65, 65, 65);
		SDL_RenderFillRect(renderer, &Pinbox);
		SDL_SetRenderDrawColor(renderer, 85, 85, 85, 85);
		SDL_RenderFillRect(renderer, &BarBox);
		SDL_SetRenderDrawColor(renderer, 255, 196, 0, 0);
		SDL_RenderFillRect(renderer, &timeleft);
		SDL_SetRenderDrawColor(renderer, 156, 90, 60, 0);
		SDL_RenderCopy(renderer, EnterButton, NULL, &EnterButtonRect);
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

		SDL_RenderCopy(renderer, Pinholes[0], NULL, &PinholesRect[0]);
		SDL_RenderCopy(renderer, Pinholes[1], NULL, &PinholesRect[1]);
		SDL_RenderCopy(renderer, Pinholes[2], NULL, &PinholesRect[2]);
		SDL_RenderCopy(renderer, Pinholes[3], NULL, &PinholesRect[3]);
		SDL_RenderCopy(renderer, Pinholes[4], NULL, &PinholesRect[4]);
		SDL_RenderCopy(renderer, Pinholes[5], NULL, &PinholesRect[5]);
		SDL_RenderCopy(renderer, Pins[0], NULL, &PinsRect[0]);
		SDL_RenderCopy(renderer, Pins[1], NULL, &PinsRect[1]);
		if (highscore[0] >= 500)
			SDL_RenderCopy(renderer, level1reminder, NULL, &level1reminderRect);
		if(instructing == true)
	    	SDL_RenderCopy(renderer, levelinstructions[0], NULL, &levelinstructionsRect[0]);
		break;
	//level 2
	case 3:
		SDL_SetRenderDrawColor(renderer, 64, 31, 0, 0);
		SDL_RenderFillRect(renderer, &table);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &wire);
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 40);
		SDL_RenderFillRect(renderer, &LightRadio);
		SDL_RenderFillRect(renderer, &EnterButtonRect);
		SDL_SetRenderDrawColor(renderer, 65, 65, 65, 65);
		SDL_RenderFillRect(renderer, &Pinbox);
		SDL_SetRenderDrawColor(renderer, 85, 85, 85, 85);
		SDL_RenderFillRect(renderer, &BarBox);
		SDL_SetRenderDrawColor(renderer, 255, 196, 0, 0);
		SDL_RenderFillRect(renderer, &timeleft);
		SDL_SetRenderDrawColor(renderer, 156, 90, 60, 0);
		SDL_RenderCopy(renderer, EnterButton, NULL, &EnterButtonRect);
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


		SDL_RenderCopy(renderer, Pinholes[0], NULL, &PinholesRect[0]);
		SDL_RenderCopy(renderer, Pinholes[1], NULL, &PinholesRect[1]);
		SDL_RenderCopy(renderer, Pinholes[2], NULL, &PinholesRect[2]);
		SDL_RenderCopy(renderer, Pinholes[3], NULL, &PinholesRect[3]);
		SDL_RenderCopy(renderer, Pinholes[4], NULL, &PinholesRect[4]);
		SDL_RenderCopy(renderer, Pinholes[5], NULL, &PinholesRect[5]);
		SDL_RenderCopy(renderer, Pinholes[6], NULL, &PinholesRect[6]);
		SDL_RenderCopy(renderer, Pinholes[7], NULL, &PinholesRect[7]);
		SDL_RenderCopy(renderer, Pinholes[8], NULL, &PinholesRect[8]);
		SDL_RenderCopy(renderer, Pins[0], NULL, &PinsRect[0]);
		SDL_RenderCopy(renderer, Pins[1], NULL, &PinsRect[1]);
		SDL_RenderCopy(renderer, Pins[2], NULL, &PinsRect[2]);
		if (highscore[1] >= 600)
			SDL_RenderCopy(renderer, level2reminder, NULL, &level2reminderRect);
		if (instructing == true)
			SDL_RenderCopy(renderer, levelinstructions[1], NULL, &levelinstructionsRect[1]);
		break;
		//level 3
	case 4:
		SDL_SetRenderDrawColor(renderer, 64, 31, 0, 0);
		SDL_RenderFillRect(renderer, &table);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &wire);
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 40);
		SDL_RenderFillRect(renderer, &LightRadio);
		SDL_RenderFillRect(renderer, &EnterButtonRect);
		SDL_SetRenderDrawColor(renderer, 65, 65, 65, 65);
		SDL_RenderFillRect(renderer, &Pinbox);
		SDL_SetRenderDrawColor(renderer, 85, 85, 85, 85);
		SDL_RenderFillRect(renderer, &BarBox);
		SDL_SetRenderDrawColor(renderer, 255, 196, 0, 0);
		SDL_RenderFillRect(renderer, &timeleft);
		SDL_SetRenderDrawColor(renderer, 156, 90, 60, 0);
		SDL_RenderCopy(renderer, EnterButton, NULL, &EnterButtonRect);
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


		SDL_RenderCopy(renderer, Pinholes[0], NULL, &PinholesRect[0]);
		SDL_RenderCopy(renderer, Pinholes[1], NULL, &PinholesRect[1]);
		SDL_RenderCopy(renderer, Pinholes[2], NULL, &PinholesRect[2]);
		SDL_RenderCopy(renderer, Pinholes[3], NULL, &PinholesRect[3]);
		SDL_RenderCopy(renderer, Pinholes[4], NULL, &PinholesRect[4]);
		SDL_RenderCopy(renderer, Pinholes[5], NULL, &PinholesRect[5]);
		SDL_RenderCopy(renderer, Pinholes[6], NULL, &PinholesRect[6]);
		SDL_RenderCopy(renderer, Pinholes[7], NULL, &PinholesRect[7]);
		SDL_RenderCopy(renderer, Pinholes[8], NULL, &PinholesRect[8]);
		SDL_RenderCopy(renderer, Pins[0], NULL, &PinsRect[0]);
		SDL_RenderCopy(renderer, Pins[1], NULL, &PinsRect[1]);
		SDL_RenderCopy(renderer, Pins[3], NULL, &PinsRect[3]);
		if (highscore[2] >= 600)
			SDL_RenderCopy(renderer, level3reminder, NULL, &level3reminderRect);
		if (instructing == true)
			SDL_RenderCopy(renderer, levelinstructions[2], NULL, &levelinstructionsRect[2]);
		break;
		//level 4
	case 5:
		SDL_SetRenderDrawColor(renderer, 64, 31, 0, 0);
		SDL_RenderFillRect(renderer, &table);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRect(renderer, &wire);
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, 40);
		SDL_RenderFillRect(renderer, &LightRadio);
		SDL_RenderFillRect(renderer, &EnterButtonRect);
		SDL_SetRenderDrawColor(renderer, 65, 65, 65, 65);
		SDL_RenderFillRect(renderer, &Pinbox);
		SDL_SetRenderDrawColor(renderer, 85, 85, 85, 85);
		SDL_RenderFillRect(renderer, &BarBox);
		SDL_SetRenderDrawColor(renderer, 255, 196, 0, 0);
		SDL_RenderFillRect(renderer, &timeleft);
		SDL_SetRenderDrawColor(renderer, 156, 90, 60, 0);
		SDL_RenderCopy(renderer, EnterButton, NULL, &EnterButtonRect);
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


		SDL_RenderCopy(renderer, Pinholes[0], NULL, &PinholesRect[0]);
		SDL_RenderCopy(renderer, Pinholes[1], NULL, &PinholesRect[1]);
		SDL_RenderCopy(renderer, Pinholes[2], NULL, &PinholesRect[2]);
		SDL_RenderCopy(renderer, Pinholes[3], NULL, &PinholesRect[3]);
		SDL_RenderCopy(renderer, Pinholes[4], NULL, &PinholesRect[4]);
		SDL_RenderCopy(renderer, Pinholes[5], NULL, &PinholesRect[5]);
		SDL_RenderCopy(renderer, Pinholes[6], NULL, &PinholesRect[6]);
		SDL_RenderCopy(renderer, Pinholes[7], NULL, &PinholesRect[7]);
		SDL_RenderCopy(renderer, Pinholes[8], NULL, &PinholesRect[8]);
		SDL_RenderCopy(renderer, Pinholes[9], NULL, &PinholesRect[9]);
		SDL_RenderCopy(renderer, Pins[0], NULL, &PinsRect[0]);
		SDL_RenderCopy(renderer, Pins[1], NULL, &PinsRect[1]);
		SDL_RenderCopy(renderer, Pins[2], NULL, &PinsRect[2]);
		SDL_RenderCopy(renderer, Pins[3], NULL, &PinsRect[3]);
		if (highscore[3] >= 600)
			SDL_RenderCopy(renderer, level4reminder, NULL, &level4reminderRect);
		if (instructing == true)
			SDL_RenderCopy(renderer, levelinstructions[3], NULL, &levelinstructionsRect[3]);
		break;
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	std::ofstream file2("data2.txt");
	std::ofstream file("data.txt");
	file << highscore[0] << std::endl;
	file << highscore[1] << std::endl;
	file << highscore[2] << std::endl;
	file << highscore[3] << std::endl;
	file << highscore[4] << std::endl;
	file << highscore[5] << std::endl;
	file << highscore[6] << std::endl;
	file << highscore[7] << std::endl;
	file << highscore[8] << std::endl;
	file << highscore[9] << std::endl;
	file2 << level << std::endl;
	file2.close();
	file.close();
	InputManager::Release();
	inputmanager = NULL;
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	std::cout << "game cleaned :)" << std::endl;
}