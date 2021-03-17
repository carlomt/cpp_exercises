#include <iostream>
#include <sstream>
#include <random>
#include <fstream>

#include "Vector.hh"
#include "Airplane.hh"
#include "Initializer.hh"

using std::cout;
using std::endl;
using std::cerr;

using generator = std::mt19937_64;

int main(int argc, char *argv[])
{
  int seed = 1234;
  const int N_airplanes = 10;
  const double timelimit = 1000;
  
  std::random_device rd;
  if(!seed)
    {
      seed = rd();
    }
  // std::shared_ptr<generator>
  auto gen = std::make_shared<generator>(seed); 
  std::uniform_real_distribution<> unif01(0., 1.);

  std::vector< std::unique_ptr<Airplane> > allAirplanes;
  Initializer<generator> init(gen, 100, 3);
 
  for(size_t i=0; i<N_airplanes; ++i)
    {      
      allAirplanes.emplace_back(init.Generate());
    }
  cout<<"allAirplanes.size(): "<<allAirplanes.size()<<endl;

  // time evolution
  size_t t = 0;
  while(allAirplanes.size()>0 && t<=timelimit)
    {
      cout<<" Number of airplanes at t = "<<t<<" "<<allAirplanes.size()<<endl;      
      // const auto end = allAirplanes.end();
      // for(auto it = allAirplanes.begin(); it!=end; ++it)
      // for (const auto& airplane : allAirplanes)
      auto it = allAirplanes.begin();
      auto end = allAirplanes.end();
      while(it != allAirplanes.end())
	{
	  const auto& airplane = *it;
	  airplane->Move();
	  for(const auto& otherAirplane : allAirplanes)
	    {
	      if (*airplane == *otherAirplane) continue;
	      if (Distance(airplane->Position(), otherAirplane->Position()) < 5)
		{
		  cout<<"Missed collision between "<<airplane->ID()<<" and "<<otherAirplane->ID()
		      <<" at time "<<t<<endl;
		}
	    }
	  double dist = Distance(airplane->Position(),Vector(0,0,0));
	  cout << "Airplane "<<airplane->ID()<<" distance from origin: "<<dist<<endl;
	  if (dist<30)
	    {
	      cout<<"Airplane "<<airplane->ID()<<" is landing"<<endl;
	      allAirplanes.erase(it);
	    }
	  else
	    {
	      ++it;
	    }
	}
      t++;
    }
  cout<<"End of program"<<endl;
  return 0;
}
