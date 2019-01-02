#include <stdio.h>
#include <SDL2/SDL.h>

int main(void)
{
	//SDL Initialization
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	//Creating a window
	SDL_Window *main_window;
	SDL_CreateWindow("MemGame",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					800,
					600,
					SDL_WINDOW_OPENGL );

	//Waiting 3 seconds
	SDL_Delay(3000);

	//Destroying window and quitting SDL
	SDL_DestroyWindow(main_window);
	SDL_Quit();
}