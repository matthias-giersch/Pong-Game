#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
    Paddle(
        const sf::Vector2f& size, 
        const sf::Color& color,
        const sf::Vector2f& position,
        const std::string& texturePath
    );

    void update(sf::RenderWindow& window, sf::Time deltaTime);
    void init();

    void setKeyUp(sf::Keyboard::Key key);
    void setKeyDown(sf::Keyboard::Key key);

private:
    sf::Keyboard::Key keyUp{};
    sf::Keyboard::Key keyDown{};
    sf::Vector2f initialPosition{};
    sf::Texture texture;
    sf::Time elapsedTime{sf::Time::Zero};

    float speed{ 1000.f };
    int frame{ 0 };
    int totalFrames{ 20 };
};
