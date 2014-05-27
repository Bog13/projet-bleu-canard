#ifndef EVENTQUEST_H
#define EVENTQUEST_H

#include <event.h>
/*
    Signal émis par la validation d'une quête.
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
