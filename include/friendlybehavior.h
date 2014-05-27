#ifndef FRIENDLYBEHAVIOR_H
#define FRIENDLYBEHAVIOR_H

#include <behavior.h>

/*
    IA pour les pets (ou gentils follower) qui suivront le joueur, en attaquant, paniquant etc.
*/

class FriendlyBehavior : public Behavior
{
    public:
        FriendlyBehavior();
        virtual ~FriendlyBehavior();
    protected:
    private:
};

#endif // FRIENDLYBEHAVIOR_H
