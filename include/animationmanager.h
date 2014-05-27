#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include "animation.h"

class AnimationManager
{
    public:
        AnimationManager();
        virtual ~AnimationManager();
    protected:
        Animation *m_animation;
    private:
};

#endif // ANIMATIONMANAGER_H
