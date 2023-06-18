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

void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = -2;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    // DEBUG remove later
    for (auto elem : this->supportedKeys)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

// Constructors/Destructors

Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Functions

void Game::endApplication()
{
    std::cout << "Ending an app \n";
}

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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    // render items
    if (!this->states.empty())
        this->states.top()->render();

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
