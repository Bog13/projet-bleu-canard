#ifndef EVENTTALK_H
#define EVENTTALK_H

#include "event.h"

/*
    Signal �mis par une discussion entre characters.
*/

class EventTalk : public Event
{
    public:
        EventTalk();
        virtual ~EventTalk();
    protected:
    private:
};

#endif // EVENTTALK_H
