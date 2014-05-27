#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <utility>

/*
    Contient les méthodes générales (sauvegarder dans un fichier par ex)
*/

class Tool
{
    public:
        Tool();
        static std::pair<int,int> toIso(int x,int y);
        virtual ~Tool();
    protected:

    private:
};

#endif // TOOL_H
