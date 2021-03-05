//
// Created by paul on 05/03/2021.
//

#ifndef LOOKAWAYTIMER_SOUND_H
#define LOOKAWAYTIMER_SOUND_H

#include <QtMultimedia>
#include <string>

class Sound
{
public:
    Sound(std::string);
    ~Sound();

    void play();
    void stop();

private:
    QMediaPlayer * m_player;
};


#endif //LOOKAWAYTIMER_SOUND_H
