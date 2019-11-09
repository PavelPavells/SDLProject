//============================================================================
// Name        : SDLProject.cpp
// Author      : Pavel Smirnov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
using namespace std;
using namespace Methods;

int main(int args, char* argv[]) {

	cout << "------------------------STARTING PROGRAMM----------------------------" << endl;
	cout << "" << endl;

	Screen screen;
	if(screen.init() == false) {
		cout << "Error Initializing SDL." << endl;
	}
	while(true) {
		if(screen.processEvents() == false) {                  			// Update Particles
			break;														// Draw particles
		}																// Check For Messages/Events
	}
	screen.close();

	cout << "++++++++++++++++++PROGRAMM SUCCESFULLY WORKS+++++++++++++++++++++++++++" << endl;
	cout << "" << endl;
	cout << "-------------------------FINISH PROGRAMM-----------------------------" << endl;
	return 0;
}
