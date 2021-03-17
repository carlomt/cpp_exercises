#include "Vector.hh"
#include <cmath>

Vector::Vector(const double x, const double y, const double z) :
  x(x),
  y(y),
  z(z)
{};

double Vector::modulus2()
{
  return x*x + y*y +z*z;
}


double Vector::modulus()
{
  return std::sqrt(modulus2());
}

double Vector::rho()
{
  return modulus();
}

double Vector::theta()
{
  return std::atan2(std::sqrt(x*x+y*y),z);
}

double Vector::phi()
{
  return std::atan2(y,x);
}

Vector &Vector::operator+=(const Vector &v)
{
  x += v.X();
  y += v.Y();
  z += v.Z();
  return *this;
}

Vector &Vector::operator-=(const Vector &v)
{
  x -= v.X();
  y -= v.Y();
  z -= v.Z();
  return *this;
}

Vector &Vector::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector &Vector::operator/=(float scalar)
{
    assert(scalar!=0);
    scalar = 1. / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector operator+ (const Vector& a, const Vector& b)
{
  return Vector(a.X()+b.X(), a.Y()+b.Y(), a.Z()+b.Z());
}

Vector operator- (const Vector& a, const Vector& b)
{
  return Vector(a.X()-b.X(), a.Y()-b.Y(), a.Z()-b.Z());
}

double operator* (const Vector& a, const Vector& b)
{
  return (a.X()*b.X() + a.Y()*b.Y() + a.Z()*b.Z());
}

Vector operator* (const Vector& a, const double b)
{
  return Vector(a.X()*b, a.Y()*b, a.Z()*b);
}

Vector operator* (const double a, const Vector& b)
{
  return b*a;
}

double Distance(const Vector &v1, const Vector &v2)
{
  Vector distance(v1 - v2);
  return distance.modulus();
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
  os << "(" << v.X() << ", " << v.Y() << ", " << v.Z() << ")";
  return os;
}
