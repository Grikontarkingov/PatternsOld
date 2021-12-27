#pragma once
#include <iostream>
#include <utility>

#include "DynamicObject.h"
#include "Bomb.h"
#include "ScreenSingleton.h"

class BombDecorator : public DynamicObject{
public:
    BombDecorator(Bomb bomb) : m_bomb(std::move(bomb)){}
    void Move(uint16_t time) override;
    void Draw() const override;

    void SetPos(double  nx, double ny) override;
    uint16_t GetWidth() const override;

private:
    Bomb m_bomb;
};