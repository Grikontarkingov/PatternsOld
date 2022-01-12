#pragma once

#include <vector>

#include "Bomb.h"

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual void Reset() = 0;
    virtual bool isDone() const = 0;
    virtual void Next() = 0;
    virtual Bomb* GetBomb() = 0;
};

class BombIterator : public Iterator{
public:
    BombIterator(std::vector<DynamicObject*>& vecDyn);

    void Reset() override;
    bool isDone() const override;
    void Next() override;
    Bomb* GetBomb() override;
private:
    void FindBomb();

    Bomb* m_bomb;
    std::vector<DynamicObject*>& m_vecDynamicObj;
    int m_curIndex;
};

class BombEvenOddIterator : public Iterator{
public:
    BombEvenOddIterator(std::vector<DynamicObject*>& vecDyn);

    void Reset() override;
    bool isDone() const override;
    void Next() override;
    Bomb* GetBomb() override;
private:
    void FindEvenBomb();
    void FindOddBomb();
    bool isDoneEven() const;
    bool isDoneOdd() const;

    Bomb* m_bomb;
    std::vector<DynamicObject*>& m_vecDynamicObj;
    int m_curEvenIndex;
    int m_curOddIndex;
};