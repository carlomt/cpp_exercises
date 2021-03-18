#ifndef AIRPLANE_HH
#define AIRPLANE_HH

#include <iostream>
#include "Vector.hh"

class Airplane{
public:
  Airplane(const int id, const Vector& position, const Vector& direction, const double speed);
  Airplane(const Airplane& other);
  Airplane(Airplane&& other) noexcept;  
  virtual ~Airplane() = default;
  
  // inline Vector Direction(){return fDirection;};
  // inline Vector Position(){return fPosition;};
  // inline int ID(){return fId;};
  // inline double Speed(){return fSpeed;};
  inline const Vector& Direction() const {return fDirection;};
  inline const Vector& Position() const {return fPosition;};
  inline int ID() const {return fId;};
  inline double Speed() const {return fSpeed;};
  bool operator==(const Airplane& other);
  
  virtual void TakeAltitude();
  virtual void LoseAltitude();
  virtual void Move();

  friend std::ostream &operator << (std::ostream &os, const Airplane &a);
  
protected:
  int fId;
  Vector fPosition;
  Vector fDirection;
  double fSpeed;
};

#endif
