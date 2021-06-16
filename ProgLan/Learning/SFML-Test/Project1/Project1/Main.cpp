#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Close);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Vector2f player_size(100.0f, 150.0f);
	sf::RectangleShape kotak(player_size);
	kotak.setOrigin(player_size.x / 2, player_size.y / 2);
	sf::Texture player_texture;
	player_texture.loadFromFile("tux_from_linux.png");
	kotak.setTexture(&player_texture);
	
	sf::Vector2u texture_size = player_texture.getSize();
	texture_size.x /= 3;
	texture_size.y /= 9;

	kotak.setTextureRect(sf::IntRect(texture_size.x * 2, texture_size.y * 8, texture_size.x, texture_size.y));


	
	while (window.isOpen())
	{
		sf::Event evnt{};
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed: window.close(); break;
			case sf::Event::Resized: std::cout << "Width: " << window.getSize().x << " Height: " << window.getSize().y << std::endl; break;
			default: break;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			kotak.move(0.1f, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			kotak.move(-0.1f, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			kotak.move(0, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			kotak.move(0, -0.1f);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
			kotak.setPosition(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
		}
		

		window.clear();
		window.draw(shape);
		window.draw(kotak);
		window.display();
	}

	return 0;
}