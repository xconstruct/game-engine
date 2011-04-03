#include <SDL/SDL_opengl.h>

#include "BaseEngine.h"

BaseEngine::BaseEngine() {
	m_running = false;
}

BaseEngine::~BaseEngine() {}

bool BaseEngine::running() const {
	return m_running;
}

void BaseEngine::quit() {
	m_running = false;
}

bool BaseEngine::execute() {
	if (!onInit()) {
		return false;
	}

	m_running = true;
	SDL_Event event;
	while (m_running) {
		while (SDL_PollEvent(&event)) {
			onEvent(&event);
		}

		onLoop();
		onRender();
		SDL_GL_SwapBuffers();
	}

	onCleanup();
	return true;
}

bool BaseEngine::onInit() {
	return true;
}

void BaseEngine::onLoop() {}

void BaseEngine::onRender() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void BaseEngine::onCleanup() {}
