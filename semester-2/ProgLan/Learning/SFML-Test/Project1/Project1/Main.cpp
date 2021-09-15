#include <SFML/Graphics.hpp>
#include <iostream>


class Anim
{
public:
	static bool Animate(sf::Transformable& object, float startScale, float endScale, float duration, float deltaTime, float res, bool back)
	{
		static float frameDist;
		static float timePerFrame;
		static float elapsedTime;
		static float currentScale;
		
		frameDist = abs(endScale - startScale);
		timePerFrame = duration / (frameDist / res);
		currentScale = startScale;
		elapsedTime += deltaTime;
		//std::cout << timePerFrame << std::endl;

		
		if (elapsedTime >= timePerFrame)
		{
			/*if (currentScale >= endScale)
			{
				return false;
			}*/
			currentScale += startScale > endScale ? -res : res;
			object.setScale(currentScale, currentScale);
			elapsedTime = 0.0f;
			//std::cout << currentScale << std::endl;

		}
		return true;
	}
};


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Close);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::CircleShape shape2(100.f);
	shape2.setFillColor(sf::Color::Blue);
	shape2.setPosition(500.0f, 500.0f);

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

	window.setFramerateLimit(0);

	float x = 200;
	float y = 200;
	float height = 1000;
	const float lenght = 1000;

	float mDeltaTime = 0.0f;
	sf::Clock mClock;

	
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
		
		Anim::Animate(shape, 1.0f, 0.5f, 10.0f, mDeltaTime, 0.01f, false);
		//Animate(shape2, 1.0f, 5.0f, 1.f, mDeltaTime, 0.01f, false);



		window.clear();
		window.draw(shape);
		window.draw(shape2);

		window.draw(kotak);
		window.display();
		mDeltaTime = mClock.restart().asSeconds();
	}

	return 0;
}

