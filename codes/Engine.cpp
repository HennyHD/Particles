#include "Engine.h"
Engine::Engine() : m_Window(VideoMode(1920, 1080), "PARTICLES", Style::Default)
/*  doesn't work
	int pixelWidth = VideoMode::getDesktopMode().width;  	//Get desktop resolution
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);
	RenderWindow m_Window(vm, "PARTICLES", Style::Default);
*/

	void Engine::run()
	{
	//Timer
		Clock clock;
		Time dt = clock.getElapsedTime();
		Time restartTime = clock.restart();
		float dtAsSeconds = dt.asSeconds();

	//tester
		cout << "Starting Particle unit tests..." << endl;
		Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
		p.unitTests();
		cout << "Unit tests complete.  Starting engine..." << endl;

	//open window
		while (m_Window.isOpen())
		{
			//Extra things to do before we poll
			//Clock initialize
			restartTime;
			cout << dtAsSeconds << "Seconds" << endl;
			input();
			update(dtAsSeconds);
			draw();
		}
	}

	//Player Inputs
		void Engine::input()
		{
			Event event;
			while (m_Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)  //if event is closed, then execute close command.
					{m_Window.close(); }
				
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
						Particle pDisplay(m_Window, numPoints, mouseClickPosition)
						m_particles.push_back(pDisplay);
					}
				}
			}
		}
	//Update the scene
		void Engine::update(float dtAsSeconds)
		{
			vector<Particle>::iterator iter = m_particles.begin();
			if (iter->getTTL() > 0.0) 
			{
				iter->update(dtAsSeconds);
				++iter;
			}
			else 
			{
				iter = m_particles.erase(iter);
				cout << "iter has erased a value" << endl;
			}
		}


	//Draw the scene
		void Engine::draw()
		{
			m_Window.clear();
			for(const Particle& particle : m_particles)
			{
				m_Window.draw(particle);
			}
			m_Window.display();
		}

		
