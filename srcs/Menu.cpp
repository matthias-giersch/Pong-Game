#include "../hdrs/Menu.h"

Menu::Menu()
{
    font.loadFromFile("assets/fnt/Roboto.ttf");

    txtStartGame.setFont(font);
    txtStartGame.setString("Start Game");
    txtStartGame.setCharacterSize(100);
    txtStartGame.setPosition(390.f, 200.f);
    txtStartGame.setFillColor(sf::Color::White);

    txtQuitGame.setFont(font);
    txtQuitGame.setString("End Game");
    txtQuitGame.setCharacterSize(100);
    txtQuitGame.setPosition(390.f, 350.f);
    txtQuitGame.setFillColor(sf::Color::White);
}

void Menu::handleEvents(Game& game)
{
    sf::Event event;
    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game.window.close();
        }

        if (event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Left)
        {
            if (startGameSelected)
            {
                game.changeState(Game::State::PLAY);
            }
            else if (quitGameSelected)
            {
                game.window.close();
            }
        }
    }
}

void Menu::update(Game& game)
{
    const auto mousePos = sf::Mouse::getPosition(game.window);

    if (txtStartGame.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        txtStartGame.setFillColor(sf::Color::Red);
        startGameSelected = true;
    }
    else
    {
        txtStartGame.setFillColor(sf::Color::White);
        startGameSelected = false;
    }

    if (txtQuitGame.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        txtQuitGame.setFillColor(sf::Color::Red);
        quitGameSelected = true;
    }
    else
    {
        txtQuitGame.setFillColor(sf::Color::White);
        quitGameSelected = false;
    }
}

void Menu::draw(Game& game)
{
    game.window.draw(txtStartGame);
    game.window.draw(txtQuitGame);
}
