#pragma once
#include "Game.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);
	static SDL_Texture* LoadText(const char* text, SDL_Renderer* renderer, TTF_Font* font);
};
