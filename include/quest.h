#ifndef QUEST_H
#define QUEST_H

#include "event.h"

/*
    Donne des quête à un character par le questlog
*/


class Quest
{
    public:
        Quest();
        virtual ~Quest();
    protected:
        std::vector<Event*> m_events;
    private:
};

#endif // QUEST_H
