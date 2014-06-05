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


        /// Methods

         int Getlife() { return m_life; }
        void Setlife( int val) { m_life = val; }

         int Getmana() { return m_mana; }
        void Setmana( int val) { m_mana = val; }

         int Getlevel() { return m_level; }
        void Setlevel( int val) { m_level = val; }

        float Getxp() { return m_xp; }
        void Setxp(float val) { m_xp = val; }

        float GetphysicalDefense() { return m_physicalDefense; }
        void SetphysicalDefense(float val) { m_physicalDefense = val; }

        float GetmagicalStrength() { return m_magicalStrength; }
        void SetmagicalStrength(float val) { m_magicalStrength = val; }

        float GetphysicalStrength() { return m_physicalStrength; }
        void SetphysicalStrength(float val) { m_physicalStrength = val; }

        float GetmagicalDefense() { return m_magicalDefense; }
        void SetmagicalDefense(float val) { m_magicalDefense = val; }

        float Getspeed() { return m_speed; }
        void Setspeed(float val) { m_speed = val; }

        int Getorientation() { return m_orientation; }
        void Setorientation(int val) { m_orientation = val; }



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
