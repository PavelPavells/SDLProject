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

int main() {
	cout << "------------------------STARTING PROGRAMM----------------------------" << endl;

	cout << "Hello, Pavel" << endl;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	} else {
		cout << "SDL Init Success." << endl;
	}
	SDL_Quit();

	cout << "-------------------------FINISH PROGRAMM-----------------------------" << endl;

	return 0;
}
