#ifndef EVENTQUEST_H
#define EVENTQUEST_H

#include <event.h>
/*
    Signal �mis par la validation d'une qu�te.
*/


class EventQuest : public Event
{
    public:
        EventQuest();
        virtual ~EventQuest();
    protected:
    private:
};

#endif // EVENTQUEST_H
