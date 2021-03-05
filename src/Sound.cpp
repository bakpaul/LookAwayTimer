//
// Created by paul on 05/03/2021.
//

#include "Sound.h"


Sound::Sound(std::string filePath)
{
    m_player = new QMediaPlayer;
    m_player->setMedia(QUrl::fromLocalFile(filePath.c_str()));
    m_player->setVolume(50);
}

Sound::~Sound()
{

}

void Sound::play()
{
    m_player->play();
}

void Sound::stop()
{
    m_player->stop();
}
