
#include "Commonfuncion.h"


void Play()
{


	SDL_Init(SDL_INIT_EVERYTHING);
	srand((unsigned int)time(NULL));
	SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	SDL_Event e;
	Snake snake;
	SDL_Rect food;
	food.w = 20;
	food.h = 20;
	food.x = rand() % (SCREEN_WIDTH / 20) * 20;
	food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
	bool run = true;
	while (run)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
				run = false;
			}
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					run = false;
					break;
				case SDLK_w: case SDLK_UP:
					snake.setDirection(0, -1);
					Background(renderer);
					SDL_Delay(130);
					snake.Move();
					snake.ShowSnake(renderer);

					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20) * 20;
						food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
						Food(renderer, food);
					}
					Food(renderer, food);
					break;
				case SDLK_s: case SDLK_DOWN:
					snake.setDirection(0, 1);
					Background(renderer);
					SDL_Delay(130);
					snake.Move();
					snake.ShowSnake(renderer);

					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20) * 20;
						food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
						Food(renderer, food);
					}
					Food(renderer, food);
					break;
				case SDLK_a: case SDLK_LEFT:
					snake.setDirection(-1, 0);
					Background(renderer);
					SDL_Delay(130);
					snake.Move(); snake.ShowSnake(renderer);
					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20) * 20;
						food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
						Food(renderer, food);
					}
					Food(renderer, food);
					break;
				case SDLK_d: case SDLK_RIGHT:
					snake.setDirection(1, 0);
					Background(renderer);
					SDL_Delay(130);
					snake.Move();
					snake.ShowSnake(renderer);

					if (snake.isEat(food))
					{
						snake.GrowUp();
						food.x = rand() % (SCREEN_WIDTH / 20) * 20;
						food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
						Food(renderer, food);
					}
					Food(renderer, food);
					break;
				}
			}
		}

		Background(renderer);
		SDL_Delay(130);
		snake.Move();
		snake.ShowSnake(renderer);
		if (snake.isEat(food))
		{
			snake.GrowUp();
			food.x = rand() % (SCREEN_WIDTH / 20) * 20;
			food.y = rand() % (SCREEN_HEIGHT / 20) * 20;
			Food(renderer, food);
		}
		Food(renderer, food);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	int Score = 0;
	int* p = &Score;
	Play();
	std::cout << score << std::endl;
	return 0;
}


