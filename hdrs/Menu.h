#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

class Menu : public GameState
{
public:
    Menu();
    void handleEvents(Game& game) override;
    void update(Game& game) override;
    void draw(Game& game) override;

private:
    bool startGameSelected{ false };
    bool quitGameSelected{ false };

    sf::Font font;
    sf::Text txtStartGame;
    sf::Text txtQuitGame;
};
