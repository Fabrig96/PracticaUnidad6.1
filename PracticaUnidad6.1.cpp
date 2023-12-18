// Practica Unidad 6 - Fast & Furious - MAVI - Fabrizio Aguilar
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fast & Furious");
	
	sf::Vector2f posicion(0.0f, 200.0f);

	float velInicial = 2.0f;
	float velFinal = 10.0f;
	float velocidad = velInicial;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float deltaTime = 1.0f / 60.0f; 
		posicion.x += velocidad * deltaTime;

		if (velocidad < velFinal) {
			if (posicion.x > 800) {
				posicion.x = 0;
				velocidad += 1.0f;
			}
			
		}
		std::cout << "Speed: " << velocidad << std::endl;
		
		window.clear();
		
		sf::CircleShape ball(20.0f);
		ball.setFillColor(sf::Color::Blue);
		ball.setPosition(posicion);
		window.draw(ball);
		window.display();
	}

	return 0;
}
