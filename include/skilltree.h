#ifndef SKILLTREE_H
#define SKILLTREE_H
#include "skill.h"
#include <vector>

class SkillTree
{
    public:
        SkillTree();
        virtual ~SkillTree();
    protected:
        std::vector<Skill*> m_skills;
    private:
};

#endif // SKILLTREE_H
