#include "MainMenuState.h"

void MainMenuState::initKeybinds()
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

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeybinds();

    this->background.setSize(sf::Vector2f(window->getSize()));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState \n";
}

void MainMenuState::updateInput(const float& dt)
{
    this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
    this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    target->draw(this->background);
}
