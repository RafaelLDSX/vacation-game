#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.c"

int main(void)
{
	//SDL Initialization
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	//Creating a window
	SDL_Window *main_window;
	main_window = SDL_CreateWindow("MemGame",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					800,
					600,
					SDL_WINDOW_OPENGL );

	//Creating renderer
	SDL_Renderer *main_renderer;
	main_renderer = SDL_CreateRenderer(main_window,
					  -1,
					  SDL_RENDERER_ACCELERATED);

	SDL_RenderClear(main_renderer);	

	//creating rect to represent "start" option
	SDL_Rect start;

	start.x = 350;
	start.y = 275;
	start.h = 50;
	start.w = 100;

	SDL_Rect startRandom;

	startRandom.x = 350;
	startRandom.y = 375;
	startRandom.h = 50;
	startRandom.w = 100;

	//Drawing the red button
	SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(main_renderer, &start);
	SDL_RenderDrawRect(main_renderer, &start);

	//Drawing the blue button
	SDL_SetRenderDrawColor(main_renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(main_renderer, &startRandom);
	SDL_RenderDrawRect(main_renderer, &startRandom);

	//Creating point to represent mouse position
	SDL_Point mouse;

	//Actually drawing on screen
	//SDL_RenderDrawPoint(main_renderer, 1, 1);

	//Updating screen
	SDL_RenderPresent(main_renderer);

	//Creating polling of events
	SDL_Event e;
	while(1)
	{
		while(SDL_PollEvent(&e)){
			switch(e.type)
			{ 
				//case Alt+F4 or similar
				case SDL_QUIT: 
					SDL_DestroyRenderer(main_renderer);
					SDL_DestroyWindow(main_window);
					SDL_Quit();
					return 0;

				//case left click is used, check what button was pressed
				case SDL_MOUSEBUTTONDOWN:

					//writing in SDL_Point mouse its current position
					SDL_GetMouseState(&mouse.x, &mouse.y);

					//if collides with red rect
					if( SDL_PointInRect(&mouse, &start) ){

						//starting the real game
						printf("Setting up game...\n");
						printf("Starting game in choose sequence mode\n");
						setGameMode(0);
						game(main_renderer, e, mouse);

						//redrawing red and blue buttons after exiting from the game
						//red
						SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);
						SDL_RenderFillRect(main_renderer, &start);
						SDL_RenderDrawRect(main_renderer, &start);
						//blue
						SDL_SetRenderDrawColor(main_renderer, 0, 0, 255, 255);
						SDL_RenderFillRect(main_renderer, &startRandom);
						SDL_RenderDrawRect(main_renderer, &startRandom);
						//updating screen
						SDL_RenderPresent(main_renderer);
					}
					//if collides with blue rect
					if( SDL_PointInRect(&mouse, &startRandom) ){

						//starting the real game
						printf("Setting up game...\n");
						printf("Starting game in random mode\n");
						setGameMode(1);
						game(main_renderer, e, mouse);

						//redrawing red and blue buttons after exiting from the game
						//red
						SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);
						SDL_RenderFillRect(main_renderer, &start);
						SDL_RenderDrawRect(main_renderer, &start);
						//blue
						SDL_SetRenderDrawColor(main_renderer, 0, 0, 255, 255);
						SDL_RenderFillRect(main_renderer, &startRandom);
						SDL_RenderDrawRect(main_renderer, &startRandom);
						//updating screen
						SDL_RenderPresent(main_renderer);
					}
					break;
			}

		}
	}

	//Destroying window and quitting SDL
	SDL_DestroyWindow(main_window);
	SDL_Quit();
}