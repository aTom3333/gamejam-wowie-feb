#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class Entity : public sf::Transformable
{
public:
    virtual void draw(sf::RenderTarget& target) = 0;
    virtual void update() {}
    virtual sf::FloatRect boundingBox() const = 0;
};


#endif // ENTITY_HPP