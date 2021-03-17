#include "Airplane.hh"

Airplane::Airplane(const int id, const Vector& position, const Vector& direction, const double speed) :
  fId(id),
  fPosition(std::move(position)),
  fDirection(std::move(direction)),
  fSpeed(speed)
{
  // std::cout<<" Airplane constructor "<<std::endl;
}

Airplane::Airplane(const Airplane& other) :
  fId(other.fId),
  fPosition(other.fPosition),
  fDirection(other.fDirection),
  fSpeed(other.fSpeed)
{
  // std::cout<<" Airplane copy constructor "<<std::endl;
}

Airplane::Airplane(Airplane&& other) noexcept :
  fId(std::move(other.fId)),
  fPosition(std::move(other.fPosition)),
  fDirection(std::move(other.fDirection)),
  fSpeed(std::move(other.fSpeed))
{
  // std::cout<<" Airplane move constructor "<<std::endl;
}


void Airplane::TakeAltitude()
{
  fPosition += Vector(0., 0., 0.5);
}

void Airplane::LoseAltitude()
{
  fPosition -= Vector(0., 0., 0.5);
}

void Airplane::Move()
{
  // fPosition += fDirection*fSpeed;
  fPosition += fSpeed*fDirection;
}

bool Airplane::operator==(const Airplane& other)
{
  return fId==other.fId;
}

std::ostream &operator<<(std::ostream &os, const Airplane &a)
{
  os << "Airplane   \t"<< a.ID()        << std::endl 
     << "position:  \t"<< a.Position()  << std::endl
     << "direction: \t"<< a.Direction() << std::endl
     << "speed: \t"<< a.Speed() << std::endl;  
  return os;
}
