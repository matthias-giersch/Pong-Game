#pragma once

#include "GameState.h"
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"

class PlayState : public GameState
{
public:
    PlayState();
    void handleEvents(Game& game) override;
    void update(Game& game) override;
    void draw(Game& game) override;

private:
    std::unique_ptr<Ball> ball;
    std::shared_ptr<Paddle> leftPaddle;
    std::shared_ptr<Paddle> rightPaddle;

    sf::Font font;
    sf::Text scoreLeft;
    sf::Text scoreRight;
    sf::Text hyphen;

    int pointsLeft{ 0 };
    int pointsRight{ 0 };

    sf::Texture backgroundTexture;
    sf::Sprite background;
};
