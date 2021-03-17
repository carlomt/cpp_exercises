#ifndef VECTOR_HH
#define VECTOR_HH

#include <iostream>

class Vector{
public:
  Vector(const double x, const double y, const double z);

  inline double X() {return x;};
  inline double Y() {return y;};
  inline double Z() {return z;};
  inline double X() const {return x;};
  inline double Y() const {return y;};
  inline double Z() const {return z;};

  double rho();
  double theta();
  double phi();
  double modulus2();
  double modulus();
  
  Vector &operator += (const Vector &v);
  Vector &operator -= (const Vector &v);
  Vector &operator *= (float scalar);
  Vector &operator /= (float scalar);
  
  friend Vector operator+ (const Vector& a, const Vector& b);
  friend Vector operator- (const Vector& a, const Vector& b);
  friend double operator* (const Vector& a, const Vector& b);
  friend Vector operator* (const Vector& a, const double b);
  friend Vector operator* (const double a, const Vector& b);  

  friend double Distance (const Vector &v1, const Vector &v2);
  
  friend std::ostream &operator << (std::ostream &os, const Vector &v);
  
protected:
  double x, y, z;
  
};

#endif
