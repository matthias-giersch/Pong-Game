#pragma once

class Game;

class GameState
{
public:
    virtual ~GameState() = default;
    virtual void handleEvents(Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(Game& game) = 0;
};
