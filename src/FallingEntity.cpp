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

    move(0, 200*fallingSpeed * GlobalClock::lapTime().asSeconds());
    fallingSpeed += 9.81 * GlobalClock::lapTime().asSeconds();
    if(fallingSpeed > 0.5)
        fallingSpeed = 3;

    entity_->setPosition(getPosition());
    entity_->setScale(getScale());
    entity_->setRotation(getRotation());
    
    for(auto const& entity : entitites_) {
        if(entity.get() != this) {
            sf::FloatRect intersection{};
            if((boundingBox().intersects(entity->boundingBox(), intersection) && intersection.top <= prev_pos.y + boundingBox().height)
                || boundingBox().top + boundingBox().height >= entity->boundingBox().top)
            {
                move(0, -intersection.height);
                fallingSpeed = 0.0f;
            }
        }
    }
    
    entity_->setPosition(getPosition());
    
    entity_->update();
}

sf::FloatRect FallingEntity::boundingBox() const
{
    return entity_->boundingBox();
}
