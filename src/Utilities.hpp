#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>
#include <filesystem>

sf::Vector2f normalize(const sf::Vector2f& source);
void fit(sf::Sprite& s);

sf::Color static makeHSV(int hue, float sat, float val, float alpha);

// hue: 0-360°; sat: 0.f-1.f; val: 0.f-1.f
sf::Color makeHSV(int hue, float sat, float val, float alpha);

int random(int min, int max);
int random(int max);

template<typename T>
void centerOrigin(T& t) {
    t.setOrigin(t.getLocalBounds().width/2.0, t.getLocalBounds().height/2.0);
}

std::filesystem::path strip_root(const std::filesystem::path& p);

#endif // !UTILITIES_H