#ifndef PAUSEMANAGER_H
#define PAUSEMANAGER_H
#include <vector>
#include "pause.h"
#include "pauseobserver.h"

class PauseManager
{
    public:
        PauseManager();
        virtual ~PauseManager();
    protected:
        Pause* m_pause;
        std::vector<PauseObserver*> m_vecObserver;
    private:
};

#endif // PAUSEMANAGER_H
