#include "../hdrs/PlayState.h"

PlayState::PlayState()
{
    leftPaddle = std::make_shared<Paddle>(
        sf::Vector2f(30.f, 200.f),
        sf::Color::Magenta,
        sf::Vector2f(30.f, 310.f),
        "assets/graphics/paddle.png");

    rightPaddle = std::make_shared<Paddle>(
        sf::Vector2f(30.f, 200.f),
        sf::Color::Magenta,
        sf::Vector2f(1250.f, 310.f),
        "assets/graphics/paddle.png");

    ball = std::make_unique<Ball>(
        20.f, sf::Color::Magenta,
        sf::Vector2f(640.f, 310.f),
        leftPaddle, rightPaddle);

    font.loadFromFile("assets/fnt/Roboto.ttf");
    backgroundTexture.loadFromFile("assets/graphics/background.png");
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);

    scoreLeft.setFont(font);
    scoreLeft.setCharacterSize(80);
    scoreLeft.setPosition(510.f, 10.f);

    hyphen.setFont(font);
    hyphen.setCharacterSize(80);
    hyphen.setString("-");
    hyphen.setPosition(630.f, 10.f);

    scoreRight.setFont(font);
    scoreRight.setCharacterSize(80);
    scoreRight.setPosition(750.f, 10.f);

    leftPaddle -> setKeyUp(sf::Keyboard::W);
    leftPaddle -> setKeyDown(sf::Keyboard::S);
    rightPaddle -> setKeyUp(sf::Keyboard::Up);
    rightPaddle -> setKeyDown(sf::Keyboard::Down);
}

void PlayState::handleEvents(Game& game)
{
    sf::Event event;
    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game.window.close();
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Space)
                ball -> init();
            else if (event.key.code == sf::Keyboard::Escape)
                game.changeState(Game::State::MAINMENU);
        }
    }
}

void PlayState::update(Game& game)
{
    ball -> update(game.window, game.frameDeltaTime);
    leftPaddle -> update(game.window, game.frameDeltaTime);
    rightPaddle -> update(game.window, game.frameDeltaTime);

    if (ball -> getPosition().x <= 0)
    {
        pointsRight++;
        ball -> init();
        leftPaddle -> init();
        rightPaddle -> init();
    }
    else if (ball -> getPosition().x >= game.window.getSize().x)
    {
        pointsLeft++;
        ball -> init();
        leftPaddle -> init();
        rightPaddle -> init();
    }

    scoreLeft.setString(Game::numberToString(pointsLeft));
    scoreRight.setString(Game::numberToString(pointsRight));
}

void PlayState::draw(Game& game)
{
    game.window.draw(background);
    game.window.draw(*ball);
    game.window.draw(*leftPaddle);
    game.window.draw(*rightPaddle);
    game.window.draw(scoreLeft);
    game.window.draw(scoreRight);
    game.window.draw(hyphen);
}
