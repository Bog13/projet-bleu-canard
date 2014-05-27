#ifndef EVENTGOTO_H
#define EVENTGOTO_H

#include "event.h"

/*
    signal émis par la position d'un character.
*/

class EventGoto : public Event
{
    public:
        EventGoto();
        virtual ~EventGoto();
    protected:
    private:
};

#endif // EVENTGOTO_H
