#include <stdio.h>
#include <SDL2/SDL.h>
#include "util.c"

int game(SDL_Renderer *renderer, SDL_Event e, SDL_Point mouse)
{
	initializeCounter();
	int *sequence = mallocSequence(3);

	//state to identify if it's time to record buttons or check sequence (always starts on 0, which means 'record state')
	int subState = 0;

	//button cooldown
	int cooldown = 0;

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
		if ( cooldown > 0 ){
			cooldown -= 1;
		}
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
					if( SDL_PointInRect(&mouse, &red) && cooldown <= 0 ){

						cooldown = 30;

						if(subState == 0){
							addToSequence(sequence, 1);
							printSequence(sequence);
						}
						else{
							checkAndPop(sequence, 1);
						}

						SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);

						SDL_RenderFillRect(renderer, &red);
					}
					else if( SDL_PointInRect(&mouse, &green) && cooldown <= 0 ){
						
						cooldown = 30;

						if(subState == 0){
							addToSequence(sequence, 2);
							printSequence(sequence);
						}
						else{
							checkAndPop(sequence, 2);
						}

						SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);

						SDL_RenderFillRect(renderer, &green);
					}
					else if( SDL_PointInRect(&mouse, &blue) && cooldown <= 0 ){
						
						cooldown = 30;

						if(subState == 0){
							addToSequence(sequence, 3);
							printSequence(sequence);
						}
						else{
							checkAndPop(sequence, 3);
						}

						SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);

						SDL_RenderFillRect(renderer, &blue);
					}
					break;

			}

		}

		if( cooldown <= 10 ){
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &red);
		}
		
		SDL_RenderDrawRect(renderer, &red);

		if( cooldown <= 10 ){
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &green);
		}
		SDL_RenderDrawRect(renderer, &green);

		if( cooldown <= 10 ){
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderFillRect(renderer, &blue);	
		}
		SDL_RenderDrawRect(renderer, &blue);

		SDL_RenderPresent(renderer);

		if(sequenceSize(sequence, 3) <= 0)
		{
			subState = 1;
		}

		SDL_Delay(1000/60);
	}

	return 0;
}