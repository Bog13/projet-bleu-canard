#ifndef CLOCKMANAGER_H
#define CLOCKMANAGER_H
#include "clock.h"

class ClockManager
{
    public:
        ClockManager();
        virtual ~ClockManager();
    protected:
        Clock *m_clock;
    private:
};

#endif // CLOCKMANAGER_H
