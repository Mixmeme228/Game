#include "engine.h"
#include<SFML/Audio/Music.hpp>
#include<SFML/Graphics.hpp>
int main()
{
    Music music;
    music.openFromFile("i2HARD_-_Pixel_trip__BiffHard.TOP.ogg");
    music.setLoop(true);
    music.play();

        Engine engine;
        engine.start();
    return 0;
}