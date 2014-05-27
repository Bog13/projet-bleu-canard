#ifndef QUESTLOG_H
#define QUESTLOG_H

#include "quest.h"
#include <vector>

/*
    Contient toutes les quêtes.
*/
class QuestLog
{
    public:
        QuestLog();
        virtual ~QuestLog();
    protected:
        std::vector<Quest*> m_questsInProgress;
        std::vector<Quest*> m_questsDone;
    private:
};

#endif // QUESTLOG_H
