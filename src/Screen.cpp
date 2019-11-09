/*
 * Screen.cpp
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: Pasha
 */

#include "Screen.h"

namespace Methods {

Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}
bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Fire Explosion Project", // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			SCREEN_HEIGHT,                     // width, in pixels
			SCREEN_WIDTH,                      // height, in pixels
			SDL_WINDOW_SHOWN                   // flags - see below
			);

	if (m_window == NULL) {
		//cout << "Could not create window: %s\n" << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		//cout << "========== Could not create Renderer ==========" << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		//cout << "========== Could not create Texture =========" << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false ;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x0080FFFF;
	}

	SDL_UpdateTexture(
				m_texture,
				NULL,
				buffer,
				SCREEN_WIDTH*sizeof(Uint32)
		);

		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(
				m_renderer,
				m_texture,
				NULL,
				NULL
		);
		SDL_RenderPresent(m_renderer);

	return true;
}
bool Screen::processEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
void Screen::close() {
	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace caveofprogramming */