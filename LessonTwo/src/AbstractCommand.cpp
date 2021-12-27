#include "AbstractCommand.h"

void DeleteDynamicCommand::Execute(){
    auto it = m_dynamicObj.begin();
    for (; it != m_dynamicObj.end(); it++) {
        if (*it == m_pBomb) {
            m_dynamicObj.erase(it);
            break;
        }
    }
}

void DeleteStaticCommand::Execute() {
    auto it = m_staticObj.begin();
    for (; it != m_staticObj.end(); it++) {
        if (*it == m_pObj) {
            m_staticObj.erase(it);
            break;
        }
    }
}

void DropBombCommand::Execute(){
    MyTools::WriteToLog(std::string(__func__) + " was invoked");

    double x = m_plane->GetX() + 4;
    double y = m_plane->GetY() + 2;

    Bomb* pBomb = new Bomb;
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(m_bombSpeed);
    pBomb->SetPos(x, y);
    pBomb->SetWidth(m_craterSize);

    m_dynamicObj.push_back(pBomb);
}

void DropNewBombCommand::Execute(){
    MyTools::WriteToLog(std::string(__func__) + " was invoked");

    double x = m_plane->GetX() + 4;
    double y = m_plane->GetY() + 2;

    Bomb* pNewBomb = new Bomb;
    pNewBomb->SetDirection(0.3, 1);
    pNewBomb->SetSpeed(m_bombSpeed);
    pNewBomb->SetPos(x, y);
    pNewBomb->SetWidth(m_craterSize);
    BombDecorator* pNewBombDec = new BombDecorator(*pNewBomb);

    m_dynamicObj.push_back(pNewBombDec);
}