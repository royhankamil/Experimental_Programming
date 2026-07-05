#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    // Create the main window
    sf::RenderWindow Window(sf::VideoMode(800, 600), "Physical Forces");
    Window.setFramerateLimit(60);

    // Load a sprite to display
    sf::RectangleShape object1;
    object1.setFillColor(sf::Color::Red);
    object1.setPosition(sf::Vector2f(600,300));
    object1.setSize(sf::Vector2f(10, 10));

	// Start the game loop
    while (Window.isOpen())
    {
        // Process events
        sf::Clock clock;
        sf::Event Event;
        float dt = clock.restart().asSeconds();
        while (Window.waitEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                Window.close();

            float speed = 4;
            std::cout << dt << std::endl;
            object1.move(speed * dt, 0);

            Window.clear(sf::Color::Black);

            // Clear screen
            Window.draw(object1);

            // Update the window
            Window.display();
        }
    }

    return 0;
}
