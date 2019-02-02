#ifndef FALLINGENTITY_HPP
#define FALLINGENTITY_HPP


#include "Entity.hpp"
#include <memory>
#include <vector>


class FallingEntity : public Entity
{
    public:
        explicit FallingEntity(std::unique_ptr<Entity> base_entity, std::vector<std::unique_ptr<Entity>> const& entities);
        void draw(sf::RenderTarget& target) override;
        void update() override;
        sf::FloatRect boundingBox() const override;
    
    private:
        std::unique_ptr<Entity> entity_;
        std::vector<std::unique_ptr<Entity>> const& entitites_;
        float fallingSpeed = 0.0f;
};


#endif // FALLINGENTITY_HPP