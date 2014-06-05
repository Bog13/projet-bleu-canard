#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "object.h"

using namespace std;
using namespace sf;

class Character : public Object
{
    public:
        Character();

        Character(int life,
         int mana,
         int level,
        float positionX,
        float positionY,
        float xp,
        float physicalDefense,
        float magicalStrength,
        float physicalStrength,
        float magicalDefense,
        float speed,
        int orientation);

        virtual ~Character();



    protected:

         int m_life;
         int m_mana;
         int m_level;
        float m_positionX;
        float m_positionY;
        float m_xp;
        float m_physicalDefense;
        float m_magicalStrength;
        float m_physicalStrength;
        float m_magicalDefense;
        float m_speed;
        int m_orientation;

    private:
};

#endif // CHARACTER_H
