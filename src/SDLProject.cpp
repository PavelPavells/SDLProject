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

	cout << "Hello, Pavel" << endl;

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
	SDL_DestroyWindow(window);
	SDL_Quit();

	cout << "-------------------------FINISH PROGRAMM-----------------------------" << endl;

	return 0;
}
