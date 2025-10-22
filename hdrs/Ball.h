#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Paddle.h"

class Ball : public sf::CircleShape
{
public:
    Ball(
        float radius,
        const sf::Color& color,
        const sf::Vector2f& position,
        std::shared_ptr<Paddle> leftPaddle,
        std::shared_ptr<Paddle> rightPaddle
    );

    void init();
    void update(sf::RenderWindow& window, sf::Time deltaTime);

private:
    int direction{ 1 };
    float speed{ 0.f };
    sf::Vector2f movement{ 0.f, 0.f };
    sf::Texture texture;

    std::shared_ptr<Paddle> leftPaddle;
    std::shared_ptr<Paddle> rightPaddle;
};
