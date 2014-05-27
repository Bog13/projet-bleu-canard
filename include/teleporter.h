#ifndef TELEPORTER_H
#define TELEPORTER_H
/*
    Permet de se téléporter dans une zone
*/
#include "trigger.h"
#include "area.h"
class Teleporter: public Trigger
{
    public:
        Teleporter();
        virtual ~Teleporter();
    protected:
        Area* m_area;
    private:
};

#endif // TELEPORTER_H
