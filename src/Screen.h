/*
 * Screen.h
 *
 *  Created on: 10 Nov 2019
 *      Author: Pavel Smirnov
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace Methods {
class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
	void boxBlur();
};
} /* namespace Methods */
#endif /* SCREEN_H_ */
