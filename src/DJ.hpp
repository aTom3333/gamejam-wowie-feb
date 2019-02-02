#ifndef DJ_HPP
#define DJ_HPP

#include <filesystem>
#include <map>
#include <string>

#include <SFML/Audio.hpp>

class DJ
{
public :    

    static DJ& getInstance();

    void playSound(const std::string& name, bool forced = false);

    void playMusic(const std::string& name);
    void stopMusic(const std::string& name);
    void stopAllMusic();

	bool isSoundPlaying(const std::string& name);

private :
    DJ();
    DJ(DJ&) = delete;
    DJ(DJ&&) = delete;
    DJ& operator=(DJ&) = delete;
    DJ& operator=(DJ&&) = delete;

    std::map<std::string, sf::Sound>                  sounds_;
    std::map<std::string, std::unique_ptr<sf::Music>> musics_;
};

#endif //DJ_HPP
