#ifndef EVENTLETTER_H
#define EVENTLETTER_H

#include <event.h>

/*
    Signal �mis par l'ouverture d'une lettre, voire sa r�ception ?
*/

class EventLetter : public Event
{
    public:
        EventLetter();
        virtual ~EventLetter();
    protected:
    private:
};

#endif // EVENTLETTER_H
