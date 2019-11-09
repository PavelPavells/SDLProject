/*
 * Screen.h
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: Pasha
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL2/SDL.h>

namespace Methods {

class Screen {
public:
	const static int SCREEN_HEIGHT = 800;
	const static int SCREEN_WIDTH = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace caveofprogramming */

#endif /* SCREEN_H_ */
