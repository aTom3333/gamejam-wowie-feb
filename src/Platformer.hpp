#ifndef PLATFORMER_HPP
#define PLATFORMER_HPP

#include "Screen.hpp"


class Platformer : public Screen
{
    public:
        std::unique_ptr<Screen> execute() override;
};


#endif // PLATFORMER_HPP