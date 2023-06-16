#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

class State
{
 private:
    std::vector<sf::Texture*> textures;

 public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void render() = 0;
};
