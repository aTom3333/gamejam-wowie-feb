#include "FallingEntity.hpp"
#include "GlobalClock.hpp"
#include <utility>


FallingEntity::FallingEntity(std::unique_ptr<Entity> base_entity, std::vector<std::unique_ptr<Entity>> const& entities) :
    entity_{std::move(base_entity)}, entitites_{entities}
{}

void FallingEntity::draw(sf::RenderTarget& target)
{
    entity_->draw(target);
}

void FallingEntity::update()
{
    auto prev_pos = getPosition();
    
    fallingSpeed += 9.81 * GlobalClock::lapTime().asSeconds();
    move(0, fallingSpeed * GlobalClock::lapTime().asSeconds());

    entity_->setPosition(getPosition());
    entity_->setScale(getScale());
    entity_->setRotation(getRotation());
    
    bool revert = false;
    for(auto const& entity : entitites_) {
        if(entity.get() != this) {
            sf::FloatRect intersection{};
            if(boundingBox().intersects(entity->boundingBox(), intersection) && intersection.top)
        }
    }
}
