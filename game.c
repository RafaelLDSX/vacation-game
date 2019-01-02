#include <stdio.h>
#include <SDL2/SDL.h>

int game(SDL_Renderer *renderer, SDL_Event e, SDL_Point mouse)
{
	//turning screen to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//creating colorful buttons and drawing them
	SDL_Rect red;

	red.x = 100;
	red.y = 275;
	red.h = 50;
	red.w = 100;

	SDL_Rect green;

	green.x = 350;
	green.y = 275;
	green.h = 50;
	green.w = 100;

	SDL_Rect blue;

	blue.x = 600;
	blue.y = 275;
	blue.h = 50;
	blue.w = 100;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderFillRect(renderer, &red);

	SDL_RenderDrawRect(renderer, &red);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderFillRect(renderer, &green);
	
	SDL_RenderDrawRect(renderer, &green);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &blue);

	SDL_RenderDrawRect(renderer, &blue);
	
	//Updating screen
	SDL_RenderPresent(renderer);

	while(1)
	{
		while(SDL_PollEvent(&e)){
			switch(e.type)
			{ 
				//case Alt+F4 or similar
				case SDL_QUIT:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					return 0;

				//case left click is used, check what button was pressed
				case SDL_MOUSEBUTTONDOWN:

					//writing in SDL_Point mouse its current position
					SDL_GetMouseState(&mouse.x, &mouse.y);

					//if collides with rect
					if( SDL_PointInRect(&mouse, &red) ){

						SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);

						SDL_RenderFillRect(renderer, &red);

						SDL_RenderDrawRect(renderer, &red);

						SDL_RenderPresent(renderer);
					}
					else if( SDL_PointInRect(&mouse, &green) ){
						
						SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);

						SDL_RenderFillRect(renderer, &green);

						SDL_RenderDrawRect(renderer, &green);

						SDL_RenderPresent(renderer);
					}
					else if( SDL_PointInRect(&mouse, &blue) ){
						
						SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);

						SDL_RenderFillRect(renderer, &blue);

						SDL_RenderDrawRect(renderer, &blue);

						SDL_RenderPresent(renderer);
					}
					break;

				case SDL_MOUSEBUTTONUP:

					//writing in SDL_Point mouse its current position
					SDL_GetMouseState(&mouse.x, &mouse.y);

					//if collides with rect
					if( SDL_PointInRect(&mouse, &red) ){

						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

						SDL_RenderFillRect(renderer, &red);

						SDL_RenderDrawRect(renderer, &red);

						SDL_RenderPresent(renderer);

						printf("1\n");
					}
					else if( SDL_PointInRect(&mouse, &green) ){

						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

						SDL_RenderFillRect(renderer, &green);

						SDL_RenderDrawRect(renderer, &green);

						SDL_RenderPresent(renderer);

						printf("2\n");
					}
					else if( SDL_PointInRect(&mouse, &blue) ){

						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

						SDL_RenderFillRect(renderer, &blue);

						SDL_RenderDrawRect(renderer, &blue);

						SDL_RenderPresent(renderer);

						printf("3\n");
					}
					break;

			}

		}
	}

	return 0;
}