#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_

#include <SDL.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <ctime>
#include<string>

#undef main

#define MAX_SIZE_OF_SNAKE 100
#define SDL_ERROR 1
#define IMG_ERROR 2


const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "Game Snake";
const int score = 0;

void Play();
void Background(SDL_Renderer* renderer);
void Food(SDL_Renderer* renderer, SDL_Rect rec);



class Snake
{
private:

	SDL_Rect snaketemp;
	std::vector<SDL_Rect> cell;
	int debug = 1;
	int LorR, UorD;
public:
	Snake()
	{

		snaketemp.h = snaketemp.w = 20;
		snaketemp.x = 0;
		snaketemp.y = 0;
		cell.push_back(snaketemp);


		UorD = 0;
		LorR = 1;
	}

	bool isEat(SDL_Rect food)
	{
		if (food.x == snaketemp.x && food.y == snaketemp.y)
		{
			return 1;
		}
		return 0;
	}

	void setDirection(int a, int b)
	{
		if ((LorR * a) != -1)
			LorR = a;
		if ((UorD * b) != -1)
			UorD = b;
	}


	void EraseTail()
	{
		cell.erase(cell.begin());
	}

	int getLorR()
	{
		return LorR;
	}

	int getUorD()
	{
		return UorD;
	}

	void GrowUp()
	{
		cell.push_back(snaketemp);
	}

	void Move()
	{
		switch (LorR)
		{
		case 0:
			snaketemp.y += 20 * UorD;
			break;
		case -1: case 1:
			snaketemp.x += 20 * LorR;
			break;
		}

		if (snaketemp.x == -20)
			snaketemp.x = SCREEN_WIDTH - 20;
		else if (snaketemp.x == (SCREEN_WIDTH))
			snaketemp.x = 0;
		if (snaketemp.y == -20)
			snaketemp.y = SCREEN_HEIGHT - 20;
		else if (snaketemp.y == (SCREEN_HEIGHT))
			snaketemp.y = 0;

		cell.push_back(snaketemp);
		EraseTail();
		std::cout << cell.size() << std::endl;

	}

	void ShowSnake(SDL_Renderer* renderer)
	{
		for (size_t i = 0; i < cell.size(); i++)
		{

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 100);
			SDL_RenderFillRect(renderer, &cell[i]);
		}
		SDL_RenderPresent(renderer);
	}



};

#endif 

