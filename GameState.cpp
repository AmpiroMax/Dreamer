#include "GameState.h"

void GameState::initKeybinds()
{
    // TODO:
    // - Add ini file
    // - check if key in supported keys exist

    std::ifstream ifs("Config/gamestate_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string keybind = "";

        while (ifs >> key >> keybind)
        {
            this->keybinds[key] = this->supportedKeys->at(keybind);
        }
    }

    ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState() {}

void GameState::endState()
{
    std::cout << "Ending GameState \n";
}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();

    // Update player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt)
{
    this->updateInput(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    this->player.render(target);
}
