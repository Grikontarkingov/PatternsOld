#pragma once

#include <sstream>
#include <vector>

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankFromString : public DestroyableGroundObject{
public:
    TankFromString(std::string& parameters);
    ~TankFromString() override;

    void SetPos(double nx, double ny) override;
    uint16_t GetWidth() const override;
    void Draw() const override;
    bool isInside(double x1, double x2) const override;
    uint16_t GetScore() const override;

private:
    TankAdaptee* m_tankAdaptee;
    std::istringstream m_parameters;
};