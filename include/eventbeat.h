#ifndef EVENTBEAT_H
#define EVENTBEAT_H

#include "event.h"

/*
    Signal �mis lors de la mort d'un ennemi.
*/

class EventBeat : public Event
{
    public:
        EventBeat();
        virtual ~EventBeat();
    protected:
    private:
};

#endif // EVENTBEAT_H
