#include "Iterator.h"

BombIterator::BombIterator(std::vector<DynamicObject*>& vecDyn)
: m_vecDynamicObj(vecDyn), m_curIndex(0), m_bomb(nullptr){
    FindBomb();
}

void BombIterator::Reset() {
m_curIndex = 0;
m_bomb = nullptr;
}

bool BombIterator::isDone() const {
return m_curIndex == m_vecDynamicObj.size();
}

void BombIterator::Next() {
++m_curIndex;
FindBomb();
}

Bomb* BombIterator::GetBomb() {
return m_bomb;
}

void BombIterator::FindBomb(){
    while (!isDone()){
        m_bomb = dynamic_cast<Bomb*>(m_vecDynamicObj[m_curIndex]);
        if(m_bomb != nullptr){
            break;
        }
        ++m_curIndex;
    }
}




BombEvenOddIterator::BombEvenOddIterator(std::vector<DynamicObject*>& vecDyn)
        : m_vecDynamicObj(vecDyn), m_curEvenIndex(0), m_curOddIndex(0), m_bomb(nullptr){
    FindEvenBomb();
    if(m_bomb == nullptr){
        FindOddBomb();
    }
}

void BombEvenOddIterator::Reset() {
    m_curEvenIndex = 0;
    m_curOddIndex = 0;
    m_bomb = nullptr;
}

bool BombEvenOddIterator::isDone() const {
    return isDoneEven() && isDoneOdd();
}

bool BombEvenOddIterator::isDoneEven() const {
    return m_curEvenIndex == m_vecDynamicObj.size();
}

bool BombEvenOddIterator::isDoneOdd() const {
    return m_curOddIndex == m_vecDynamicObj.size();
}

void BombEvenOddIterator::Next() {
    if(!isDoneEven()){
        ++m_curEvenIndex;
        FindEvenBomb();
    }
    else{
        ++m_curOddIndex;
        FindOddBomb();
    }
}

Bomb* BombEvenOddIterator::GetBomb() {
    return m_bomb;
}

void BombEvenOddIterator::FindEvenBomb(){
    while (!isDoneEven()){
        if(m_curEvenIndex % 2 == 0){
            m_bomb = dynamic_cast<Bomb*>(m_vecDynamicObj[m_curEvenIndex]);
            if(m_bomb != nullptr){
                break;
            }
        }
        ++m_curEvenIndex;
    }
}

void BombEvenOddIterator::FindOddBomb(){
    while (!isDoneOdd()){
        if(m_curOddIndex % 2 != 0){
            m_bomb = dynamic_cast<Bomb*>(m_vecDynamicObj[m_curOddIndex]);
            if(m_bomb != nullptr){
                break;
            }
        }
        ++m_curOddIndex;
    }
}