#pragma once

#include "DynamicObject.h"
#include "GameObject.h"
#include "Plane.h"
#include "SBomber.h"
#include "MyTools.h"
#include "enums/CraterSize.h"
#include "BombDecorator.h"
#include <vector>

class AbstractCommand {

public:
    virtual ~AbstractCommand() = default;
    virtual void Execute() = 0;
};

class DeleteDynamicCommand : public AbstractCommand{
public:
    DeleteDynamicCommand(DynamicObject* pBomb, std::vector<DynamicObject*>& dynamicObj) : m_pBomb(pBomb), m_dynamicObj(dynamicObj) {}

    void Execute() override;

private:
    DynamicObject* m_pBomb;
    std::vector<DynamicObject*>& m_dynamicObj;
};

class DeleteStaticCommand : public AbstractCommand{
public:
    DeleteStaticCommand(GameObject* pObj, std::vector<GameObject*>& staticObj) : m_pObj(pObj), m_staticObj(staticObj) {}

    void Execute() override;

private:
    GameObject* m_pObj;
    std::vector<GameObject*>& m_staticObj;
};

class DropBombCommand : public AbstractCommand{
public:
    DropBombCommand(const Plane* plane, std::vector<DynamicObject*>& dynamicObj, const uint16_t bombsNumber,const int bombSpeed, const int craterSize)
    : m_plane(plane), m_dynamicObj(dynamicObj), m_bombsNumber(bombsNumber), m_bombSpeed(bombSpeed), m_craterSize(craterSize) {}

    void Execute() override;
private:
    const Plane* m_plane;

    std::vector<DynamicObject*>& m_dynamicObj;

    const int m_bombSpeed;
    const int m_craterSize;
    const uint16_t m_bombsNumber;
};

class DropNewBombCommand : public AbstractCommand{
public:
    DropNewBombCommand(const Plane* plane, std::vector<DynamicObject*>& dynamicObj, const uint16_t bombsNumber, const int bombSpeed, const int craterSize)
            : m_plane(plane), m_dynamicObj(dynamicObj), m_bombsNumber(bombsNumber), m_bombSpeed(bombSpeed), m_craterSize(craterSize) {}

    void Execute() override;
private:
    const Plane* m_plane;

    std::vector<DynamicObject*>& m_dynamicObj;

    const int m_bombSpeed;
    const int m_craterSize;
    const uint16_t m_bombsNumber;
};