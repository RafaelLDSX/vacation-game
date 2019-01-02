#include <stdio.h>
#include <SDL2/SDL.h>

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

	//Changing renderer color to draw points
	SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);

	//creating rect to represent "start" option
	SDL_Rect start;

	start.x = 800/2;
	start.y = 600/2;
	start.h = 50;
	start.w = 100;

	SDL_RenderFillRect(main_renderer, &start);

	SDL_RenderDrawRect(main_renderer, &start);

	//Actually drawing on screen
	//SDL_RenderDrawPoint(main_renderer, 1, 1);

	//Updating screen
	SDL_RenderPresent(main_renderer);

	//Waiting 3 seconds
	SDL_Delay(3000);

	//Destroying window and quitting SDL
	SDL_DestroyWindow(main_window);
	SDL_Quit();
}