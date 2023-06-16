#include "Game.h"

// Static functions

// Initialization

void Game::initWindow()
{
    // Creates SFMl window from window.ini

    std::ifstream ifs("Config/window.ini");

    std::string title = "none";
    sf::VideoMode window_bounds(800, 600);
    unsigned frame_rate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> frame_rate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_rate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Constructors/Destructors

Game::Game()
{
    this->initWindow();
}

Game::~Game() {}

// Functions

void Game::updateDt()
{
    // Updates dt variable with the time it takes to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    // render objects

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
