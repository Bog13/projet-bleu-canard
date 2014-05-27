#ifndef NEUTRALBEHAVIOR_H
#define NEUTRALBEHAVIOR_H

#include <Behavior.h>

/*
    Comportement neutre comportant la promenade et la fuite.
*/
class NeutralBehavior : public Behavior
{
    public:
        NeutralBehavior();
        virtual ~NeutralBehavior();
    protected:
    private:
};

#endif // NEUTRALBEHAVIOR_H
