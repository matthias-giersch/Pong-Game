#include "../hdrs/Paddle.h"

Paddle::Paddle(
    const sf::Vector2f& size,
    const sf::Color& color,
    const sf::Vector2f& position,
    const std::string& texturePath
)
: keyUp(sf::Keyboard::Unknown),
keyDown(sf::Keyboard::Unknown),
initialPosition(position)
{
    setSize(size);
    setFillColor(color);
    setOrigin(size.x / 2.f, size.y / 2.f);
    setPosition(position);

    texture.loadFromFile(texturePath);
    texture.setSmooth(true);
    setTexture(&texture);
}

void Paddle::init()
{
    setPosition(initialPosition);
}

void Paddle::setKeyUp(sf::Keyboard::Key key)
{
    keyUp = key;
}

void Paddle::setKeyDown(sf::Keyboard::Key key)
{
    keyDown = key;
}

void Paddle::update(sf::RenderWindow& window, sf::Time deltaTime)
{
    elapsedTime += deltaTime;

    if (elapsedTime.asSeconds() >= 0.05f)
    {
        frame = (frame + 1) % totalFrames;
        elapsedTime = sf::Time::Zero;
    }

    const float halfHeight = getGlobalBounds().height / 2.f;
    const float windowHeight = static_cast<float>(window.getSize().y);

    if (sf::Keyboard::isKeyPressed(keyUp) && getPosition().y > halfHeight)
    {
        move(0.f, -speed * deltaTime.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(keyDown) &&
        getPosition().y < windowHeight - halfHeight)
    {
        move(0.f, speed * deltaTime.asSeconds());
    }
}
