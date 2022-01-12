#pragma once

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : public DestroyableGroundObject{
public:
    TankAdapter(TankAdaptee* tankAdaptee);
    ~TankAdapter() override;

    void SetPos(double nx, double ny) override;
    uint16_t GetWidth() const override;
    void Draw() const override;
    bool isInside(double x1, double x2) const override;
    uint16_t GetScore() const override;

private:
    TankAdaptee* m_tankAdaptee;
};