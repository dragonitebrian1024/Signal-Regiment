#include "TextureManager.h"
#include "Game.h"

SDL_Color textColor = { 255, 255, 255, 0 };


SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* renderer)
{
	SDL_Surface* tempsurface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return tex;
}

SDL_Texture* TextureManager::LoadText(const char* text, SDL_Renderer* renderer, TTF_Font* font)
{
	SDL_Surface* tempsurface = TTF_RenderText_Solid(font, text, textColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return tex;
}