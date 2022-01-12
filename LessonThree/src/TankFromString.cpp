#include "TankFromString.h"

TankFromString::TankFromString(std::string& parameters) : m_parameters(parameters){
        m_tankAdaptee = new TankAdaptee;
        std::vector<double> temp;
        for(std::string line; std::getline(m_parameters, line, ';');){
            temp.push_back(std::stod(line));
        }
        m_tankAdaptee->SetPos(temp[0], temp[1]);
        m_tankAdaptee->SetWidth((uint16_t)temp[2]);
}

TankFromString::~TankFromString() {
delete m_tankAdaptee;
}

void TankFromString::SetPos(double nx, double ny) {
m_tankAdaptee->SetPos(nx, ny);
}
uint16_t TankFromString::GetWidth() const {
return m_tankAdaptee->GetWidth();
}
void TankFromString::Draw() const {
m_tankAdaptee->Paint();
}
bool TankFromString::isInside(double x1, double x2) const {
return m_tankAdaptee->isInRange(x1, x2);
}
uint16_t TankFromString::GetScore() const {
return m_tankAdaptee->GetScore();
}