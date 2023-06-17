#pragma once

#include "GameState.h"

class Game
{
 private:
    // Variables
    sf::RenderWindow* window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    // Initialization
    void initWindow();
    void initStates();

 public:
    // Constructors/Destructors
    Game();
    virtual ~Game();

    // Functions

    // Regular
    void endApplication();

    // Updating
    void updateDt();
    void updateSFMLEvents();
    void update();

    // Rendering
    void render();

    // Main loop
    void run();
};
