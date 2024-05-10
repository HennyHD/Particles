#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "Particle.h"
#include <algorithm>
using namespace sf;
using namespace std;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;

	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Background sprite
	Texture backgroundTexture;
	Sprite backgroundSprite;

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};