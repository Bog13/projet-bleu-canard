#ifndef SOCIALBEHAVIOR_H
#define SOCIALBEHAVIOR_H

#include <behavior.h>

/*
    Comportement des NPC à envers les autres, engager un dialogue ou vendre.
*/

class SocialBehavior : public Behavior
{
    public:
        SocialBehavior();
        virtual ~SocialBehavior();
    protected:
    private:
};

#endif // SOCIALBEHAVIOR_H
