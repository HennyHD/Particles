#include "Engine.h"
Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Particles!",
		Style::Default);

	run()
	{
	//Timer
		Clock clock;
		Time getTime = clock.getElapsedTime();
		Time restartTicme = clock.restart();
		Time getTimeSec = clock.asSeconds();

	//initialize a particle
		Particle p(RenderTarget& target, int numPoints, Vector2i mouseClickPosition);

	//tester
		cout << "Starting Particle unit tests..." << endl;
		Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
		p.unitTests();
		cout << "Unit tests complete.  Starting engine..." << endl;

	//open window
		while (m_Window.isopen)
		{
			//Extra things to do before we poll
			//Clock initialize
			restartTime;
			getTimeSec;
			void input();
			void update(float dtAsSeconds);
			void draw();
		}

	//Player Inputs
		Engine::input()
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)  //if event is closed, then execute close command.
					{ window.close(); }
				
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					cout << "The Escape key was pressed" << endl;
					event.type = Event::Closed;
				}

				//loop for particles
				if (event.mouseButton.button == sf::Mouse::Left) 
				{
					cout << "the left mouse button was pressed" << endl;  //Show commands and location to terminal
					cout << "mouse x: " << event.mouseButton.x << endl;
					cout << "mouse y: " << event.mouseButton.y << endl;

					for (int i = 0; i < 5; ++i)
					{
						
						int numPoints = rand() % (50 - 25 + 1) + 25;
						Vector2i mouseClickPosition = Vector2i(event.mouseButton.x, event.mouseButton.y);
						m_particles.push_back(RenderTarget& target, int numPoints, Vector2i mouseClickPosition);
					}
				}
			}
		}
	//Update the scene
		Engine::update(float dtAsSeconds)
		{
			vector<Particle>::iterator iter = m_particles.begin();
			int i = 0;
			if (m_particles.at(i).getTTL() > 0.0) 
			{
				m_particles.at(i).update(float dt);
				++i;
			}
			else 
			{
				iter = iter.erase(iter)
				cout << "iter has erased a value" << endl;
			}
		}



		/*
		****************************************
		Draw the scene
		****************************************
		*/




	}
		
}