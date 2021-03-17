// #include <random>
// #include <cmath>
// #include "Initializer.hh"
// #include "Airplane.hh"
// #include "Vector.hh"

// const double pi = std::acos(-1);

// // template <class RNG>
// // Initializer<RNG>::Initializer(RNG &gen, const double max_distance, const double sigma) :
// //   fGen(gen),
// //   fMax_distance(max_distance),
// //   fSigma(sigma)
// // {

// // }

// template <class RNG>
// Airplane Initializer<RNG>::
// Generate()
// {
//   std::exponential_distribution<> exp(fSigma);
//   double r = fMax_distance-exp(fGen);
//   std::uniform_real_distribution<> unif(0., 2. * pi);
//   double theta = unif(fGen);  
//   return Airplane("generated",
// 		  Vector(r*std::cos(theta), r*std::sin(theta), 10),
// 		  Vector(-std::cos(theta), -std::sin(theta), 0));
// }
