#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H
/*
    Moteur de son: gère tous les ons du jeu
*/
#include "engine.h"
#include "musicmanager.h"
#include "soundmanager.h"

class SoundEngine: public Engine
{
    public:
        SoundEngine();
        virtual ~SoundEngine();
    protected:
        SoundManager* m_sManager;
        MusicManager* m_mManager;
    private:
};

#endif // SOUNDENGINE_H
