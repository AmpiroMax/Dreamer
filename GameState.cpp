#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {}

GameState::~GameState() {}

void GameState::endState()
{
    std::cout << "Ending GameState \n";
}

void GameState::updateKeyBinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::update(const float& dt)
{
    this->updateKeyBinds(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (target)
        this->player.render(target);
    this->player.render(this->window);
}
