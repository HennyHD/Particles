#include "Engine.h"
Engine::Engine() : m_Window(VideoMode(1920, 1080), "PARTICLES", Style::Default)
{

	/*if (!backgroundTexture.loadFromFile("background.png"))
    {
        cout << "Error loading background image!" << endl;
    }
	else {
		backgroundSprite.setTexture(backgroundTexture);
	}
	*/

}

	void Engine::run()
	{
	//Timer
	
		Clock clock;

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
			Time dt = clock.restart();
			float dtAsSeconds = dt.asSeconds();
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
						Particle pDisplay(m_Window, numPoints, mouseClickPosition);
						m_particles.push_back(pDisplay);
					}
				}
			}
		}
	//Update the scene
		void Engine::update(float dtAsSeconds)
		{
				   for (auto i = m_particles.begin(); i != m_particles.end();)
		   {
			   if (i->getTTL() > 0.0) // TTL expired check
			   {
				   i->update(dtAsSeconds); // calling the update here per the instructions!
				   i++;
			   }
			   else
			   {
				   i = m_particles.erase(i); // If expired then we erase it from the vector here!
			   }
		   }
		}


	//Draw the scene
		void Engine::draw()
		{
			m_Window.clear();
			m_Window.draw(backgroundSprite);

			for(const Particle& particle : m_particles)
			{
				m_Window.draw(particle);
			}
			m_Window.display();
		}

		
