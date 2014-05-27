#ifndef CREDITGRAPHICS_H
#define CREDITGRAPHICS_H

#include "graphicsengine.h"
#include "creditobserver.h"

class CreditGraphics : public GraphicsEngine, CreditObserver
{
    public:
        CreditGraphics();
        virtual ~CreditGraphics();
    protected:
    private:
};

#endif // CREDITGRAPHICS_H
