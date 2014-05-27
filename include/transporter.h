#ifndef TRANSPORTER_H
#define TRANSPORTER_H
/*
    Donne la capacité de transporter un personnage
*/
#include <vector>
#include "character.h"

class Transporter
{
    public:
        Transporter();
        virtual ~Transporter();
    protected:
        std::vector<Character*> m_vecCharacter;
    private:
};

#endif // TRANSPORTER_H
