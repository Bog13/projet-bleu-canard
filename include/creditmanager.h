#ifndef CREDITMANAGER_H
#define CREDITMANAGER_H
#include <vector>
#include "credit.h"
#include "creditobserver.h"

class CreditManager
{
    public:
        CreditManager();
        virtual ~CreditManager();
    protected:
        Credit* m_credit;
        std::vector<CreditObserver*> m_vecObserver;
    private:
};

#endif // CREDITMANAGER_H
