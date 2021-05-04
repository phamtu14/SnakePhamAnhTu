
#include "Commonfuncion.h"

void Background(SDL_Renderer* renderer)
{
	
	SDL_SetRenderDrawColor(renderer, 0, 40, 90, 100);
	SDL_RenderClear(renderer);
}
void Food(SDL_Renderer* renderer, SDL_Rect rec)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, &rec);
	SDL_RenderPresent(renderer);
}


void LogError(std::string msg, int error_code)
{
	if (error_code == SDL_ERROR)
	{
		std::cout << msg << SDL_GetError() << std::endl;
	}

	
}






