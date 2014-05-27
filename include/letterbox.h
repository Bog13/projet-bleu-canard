#ifndef LETTERBOX_H
#define LETTERBOX_H
#include <vector>
#include "letter.h"

class LetterBox
{
    public:
        LetterBox();
        virtual ~LetterBox();
    protected:
        std::vector<Letter*> m_vecLetter;
    private:
};

#endif // LETTERBOX_H
