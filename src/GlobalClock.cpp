#include "GlobalClock.hpp"
#include <algorithm>


sf::Time GlobalClock::restart() noexcept
{
    sf::Time elapsed = clock.restart();
    
    if(running)
    {
        frame = elapsed * (float)factor;
        global += frame;
        for(auto& [time, fun] : callbacks)
        {
            time -= frame;
            if(time < sf::Time::Zero)
                fun();
        }
        callbacks.erase(std::remove_if(callbacks.begin(),
                                       callbacks.end(),
                                       [](auto const& p) { return p.first < sf::Time::Zero; }),
                        callbacks.end());
    }
    else
    {
        frame = sf::Time::Zero;
    }
    
    return frameTime();
}

sf::Time GlobalClock::frameTime() const noexcept
{
    return frame;
}

void GlobalClock::stop() noexcept
{
    running = false;
}

void GlobalClock::start() noexcept
{
    running = true;
}

void GlobalClock::changeSpeed(double speed) noexcept
{
    factor = speed;
}

sf::Time GlobalClock::timeSinceStartup() const noexcept
{
    return global;
}

GlobalClock& GlobalClock::getClock()
{
    return instance;
}

void GlobalClock::executeIn(sf::Time delay, std::function<void()> fun)
{
    callbacks.emplace_back(delay, std::move(fun));
}
