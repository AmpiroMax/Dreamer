#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>

#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

class State
{
 private:
    sf::RenderWindow* window;
    std::vector<sf::Texture*> textures;

 public:
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
