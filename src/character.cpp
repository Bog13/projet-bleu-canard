#include "character.h"

Character::Character()
{
    //ctor
}

Character::Character(int life,
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
        int orientation)

{
    m_life = life;
    m_mana=mana;
    m_level=level;
    m_positionX=positionX;
    m_positionY=positionY;
    m_xp=xp;
    m_physicalDefense=physicalDefense;
    m_magicalStrength=magicalStrength;
    m_physicalStrength=physicalStrength;
    m_magicalDefense=magicalDefense;
    m_speed=speed;
    m_orientation=orientation;

}

Character::~Character()
{
    //dtor
}
