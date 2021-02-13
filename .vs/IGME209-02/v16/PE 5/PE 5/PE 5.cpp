// PE 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    sf::RectangleShape myRect(sf::Vector2f(100, 250));
    myRect.setFillColor(sf::Color::Black);
    myRect.setPosition(200, 100);

    sf::CircleShape myCirc(50);
    myCirc.setFillColor(sf::Color::Green);
    myCirc.setPosition(50, 50);

    sf::CircleShape myTri(75, 3);
    myTri.setFillColor(sf::Color(250, 150, 100));
    myTri.setPosition(500, 300);

    sf::CircleShape myHex(100, 6);
    myHex.setFillColor(sf::Color(250, 250, 250));
    myHex.setPosition(600, 100);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Yellow);

        // draw everything here...
        // window.draw(...);

        window.draw(myCirc);
        window.draw(myRect);
        window.draw(myTri);
        window.draw(myHex);

        // end the current frame
        window.display();
    }

    return 0;
}
