#ifndef INITIALIZER_HH
#define INITIALIZER_HH

#include <random>
#include <cmath>
#include <string>

#include "Initializer.hh"
#include "Vector.hh"

const double pi = std::acos(-1);

class Airplane;

template <class RNG> class Initializer{
  
public:
  Initializer(std::shared_ptr<RNG> gen, const double max_distance, const double sigma) :
    fGen(gen), fMax_distance(max_distance), fSigma(sigma), fNGenerated(0) {};
  
  // Airplane Generate();
  //Airplane
  std::unique_ptr<Airplane> Generate()
  {
    std::exponential_distribution<double> exp(fSigma);
    double r = fMax_distance-exp(*fGen);
    if(r<0)
      {
	std::cerr<<__FUNCTION__<<" distance less than 0 r: "<<r<<
	  "increase the maximum distance or decrease variability"<<std::endl;
      }
    // std::cout<<__FUNCTION__<<" r: "<<r<<std::endl;
    std::uniform_real_distribution<double> unif(0., 2. * pi);
    double theta = unif(*fGen);
    double sint = std::sin(theta);
    double cost = std::cos(theta);
    // std::cout<<__FUNCTION__<<" sin t: "<<sint<<std::endl;
    // std::cout<<__FUNCTION__<<" cos t: "<<cost<<std::endl;
    std::normal_distribution<double> normal{5,1};
    double speed = normal(*fGen);
    // double speed = 1;
    fNGenerated++;    
    return std::make_unique<Airplane>(fNGenerated,
				      Vector(r*cost, r*sint, 10),
				      Vector(-cost, -sint, 0),
				      speed);
  }
      
  
private:
  std::shared_ptr<RNG> fGen;
  double fMax_distance;
  double fSigma;
  size_t fNGenerated;
};

#endif

