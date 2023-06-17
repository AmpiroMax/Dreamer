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

class Entity
{
 private:
 protected:
    sf::RectangleShape shape;
    float movementSpeed;

 public:
    Entity();
    virtual ~Entity();

    // Functions

    virtual void move(const float& dt, const float dx, const float dy);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
