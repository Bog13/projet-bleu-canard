#ifndef AREAFACTORY_H
#define AREAFACTORY_H
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "entitygraphic.h"
#include "area.h"
#include "areagraphic.h"
#include "global.h"
using namespace std;
using namespace sf;

class AreaFactory
{
    public:
        AreaFactory();
        virtual ~AreaFactory();


        static void load();
        static AreaGraphic get(int i);

        static void saveArea(Area *area,string fileName);
        static void loadArea(Area *a,string fileName);

    protected:
        static vector<AreaGraphic> m_vector;
    private:
};

#endif // AREAFACTORY_H
