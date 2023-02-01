#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int Framedelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	std::cout << "enter a number: ";
	std::cin >> game->seed;
	game->init("Signal Regiment", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleevents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (Framedelay > frameTime)
		{
			SDL_Delay(Framedelay - frameTime);
		}
	}
	game->clean();

	return 0;
}