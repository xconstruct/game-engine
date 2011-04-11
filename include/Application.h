#ifndef APPLICATION_H
#define APPLICATION_H

#include "GameEngine.h"
#include "ResourceManager.h"

class SDL_Surface;

class Application {
public:
	Application();
	static Application * instance();

	bool running() const;
	void quit();
	bool execute();

	bool onInit();
	void onCleanup();

	int time() const;

	GameEngine * engine() const;
	ResourceManager * manager() const;

private:
	bool m_running;
	int m_fps;

	GameEngine * m_engine;
	ResourceManager * m_manager;
	SDL_Surface * m_display;
};

static Application * App = 0;

#endif /* end of include guard: APPLICATION_H */
