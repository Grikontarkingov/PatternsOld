#include "TankAdapter.h"

TankAdapter::TankAdapter(TankAdaptee* tankAdaptee) : m_tankAdaptee(tankAdaptee){}
TankAdapter::~TankAdapter(){
delete m_tankAdaptee;
}

void TankAdapter::SetPos(double nx, double ny) {
m_tankAdaptee->SetPos(nx, ny);
}
uint16_t TankAdapter::GetWidth() const {
return m_tankAdaptee->GetWidth();
}
void TankAdapter::Draw() const {
m_tankAdaptee->Paint();
}
bool TankAdapter::isInside(double x1, double x2) const {
return m_tankAdaptee->isInRange(x1, x2);
}
uint16_t TankAdapter::GetScore() const {
return m_tankAdaptee->GetScore();
}