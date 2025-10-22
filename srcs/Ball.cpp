#include "../hdrs/Ball.h"
#include <cstdlib>

Ball::Ball(
    float radius,
    const sf::Color& color,
    const sf::Vector2f& position,
    std::shared_ptr<Paddle> leftPaddle,
    std::shared_ptr<Paddle> rightPaddle
)
: leftPaddle(std::move(leftPaddle)),
rightPaddle(std::move(rightPaddle))
{
    setRadius(radius);
    setFillColor(color);
    setOrigin(radius / 2.f, radius / 2.f);
    setPosition(position);

    texture.loadFromFile("assets/graphics/ball.png");
    texture.setSmooth(true);
    setTexture(&texture);
}

void Ball::init()
{
    speed = 800.f;
    direction = std::rand() % 2;

    movement = (direction == 0)
        ? sf::Vector2f(speed, 0.f)
        : sf::Vector2f(-speed, 0.f);

    setPosition(640.f, 310.f);
}

void Ball::update(sf::RenderWindow& window, sf::Time deltaTime)
{
    const float x = getPosition().x;
    const float y = getPosition().y;
    const float windowHeight = static_cast<float>(window.getSize().y);

    sf::Vector2f leftPos = leftPaddle -> getPosition();
    sf::Vector2f rightPos = rightPaddle -> getPosition();

    if (y <= 0.f)
        movement.y = speed;
    else if (y >= windowHeight)
        movement.y = -speed;

    const auto bounds = getGlobalBounds();

    if (bounds.left < leftPos.x + (leftPaddle -> getSize().x / 2.f) - 8.f &&
        bounds.left + bounds.width > leftPos.x - (leftPaddle -> getSize().x / 2.f) &&
        bounds.top + bounds.height >= leftPos.y - (leftPaddle -> getSize().y / 2.f) &&
        bounds.top <= leftPos.y + leftPaddle -> getSize().y / 2.f)
    {
        setFillColor(leftPaddle -> getFillColor());

        if (y < leftPos.y)
            movement = { speed, -speed };
        else if (y > leftPos.y)
            movement = { speed, speed };
        else
            movement = { speed, 0.f };
    }

    else if (bounds.left < rightPos.x + (rightPaddle -> getSize().x / 2.f) &&
        bounds.left + bounds.width > rightPos.x - (rightPaddle -> getSize().x / 2.f) + 8.f &&
        bounds.top + bounds.height >= rightPos.y - (rightPaddle -> getSize().y / 2.f) &&
        bounds.top <= rightPos.y + rightPaddle -> getSize().y / 2.f)
    {
        setFillColor(rightPaddle -> getFillColor());

        if (y < rightPos.y)
            movement = { -speed, -speed };
        else if (y > rightPos.y)
            movement = { -speed, speed };
        else
            movement = { -speed, 0.f };
    }

    move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds());
}
