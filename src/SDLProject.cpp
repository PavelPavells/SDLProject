//============================================================================
// Name        : SDLProject.cpp
// Author      : Pavel Smirnov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int args, char* argv[]) {
	cout << "------------------------STARTING PROGRAMM----------------------------" << endl;

	SDL_Event event;
	const int SCREEN_HEIGHT = 800;
	const int SCREEN_WIDTH = 600;
	bool quit = false;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	} else {
		cout << "SDL Init Success." << endl;
	}

	SDL_Window *window = SDL_CreateWindow(
	        "Fire Explosion Project",          // window title
	        SDL_WINDOWPOS_UNDEFINED,           // initial x position
	        SDL_WINDOWPOS_UNDEFINED,           // initial y position
	        SCREEN_HEIGHT,                     // width, in pixels
	        SCREEN_WIDTH,                      // height, in pixels
	        SDL_WINDOW_SHOWN                   // flags - see below
	    );

	if(window == NULL) {
		cout << "Could not create window: %s\n" << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_PRESENTVSYNC
	);

	SDL_Texture *texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
	);

	if(renderer == NULL) {
		cout << "========== Could not create Renderer ==========" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if(texture == NULL) {
		cout << "========== Could not create Texture =========" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(
			buffer,
			0,
			SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)
	);

	for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		buffer[i] = 0x0080FFFF;
	}

	//buffer[30000] = 0xFFFFFFFF;

	SDL_UpdateTexture(
			texture,
			NULL,
			buffer,
			SCREEN_WIDTH*sizeof(Uint32)
	);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(
			renderer,
			texture,
			NULL,
			NULL
	);
	SDL_RenderPresent(renderer);

	while(!quit) {
			// Update Particles
			// Draw particles
			// Check For Messages/Events

		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	//SDL_Delay(2000);
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	cout << "-------------------------FINISH PROGRAMM-----------------------------" << endl;

	return 0;
}
