#include "Engine.h"
Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Particles!",
		Style::Fullscreen);

	Clock clock();

	Particle particle();
	
		
}