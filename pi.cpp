#include <iostream>
#include <sstream>
#include <random>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;

void help()
{
  cerr <<"Execute with a number to decide how many extraction." <<endl;
  cerr <<"optional arguments:"<<endl;
  cerr <<" -h, --help\t print this help"<<endl;
  cerr <<" -s, --seed\t set the seed of prng"<<endl;  
  cerr <<" -n, --number\t set number of iterations (default 10000)"<<endl;
  cerr <<" -e, --evolution\t print evolution (every <n>)"<<endl;
  cerr <<" -o, --outfile\t print on a file instead of std out"<<endl;
  cerr <<" -v, --verbose\t set verbose output"<<endl;
}

int main(int argc, char *argv[])
{
  bool verbose = false;
  unsigned int N = 10000;
  unsigned int N_evolution = 0;
  bool outfile_b = false;
  std::ofstream outfile;
  int seed = -1;
  
  for (int i = 1; i < argc; ++i)
     {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help"))
	  {
	    help();
            return 0;
	  }
	else if ((arg == "-n") || (arg == "--number"))
	  {
	    std::stringstream strValue;
	    strValue << argv[++i];
	    strValue >> N;
	  }
	else if ((arg == "-e") || (arg == "--evolution"))
	  {
	    std::stringstream strValue;
	    strValue << argv[++i];
	    strValue >> N_evolution;
	  }
	else if ((arg == "-o") || (arg == "--outfile"))
	  {
	    outfile_b = true;
	     std::string outfname(argv[++i]);
	    outfile.open(outfname);
	    cout << "The output will be on: "<< outfname <<endl;
	  }		
	else if ((arg == "-v") || (arg == "--verbose"))
	  {
	    verbose = true;
	  }
	else
	  {
	    cerr << "Input not recognized: "<<arg<<endl;
	  }
     }
  

  cout<< "Calculating pi with " << N <<" numbers." <<endl;
  
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  if(!seed)
    {
      seed = rd();
    }
  std::mt19937_64 gen(seed); 
  std::uniform_real_distribution<> dis(0., 1.);

  unsigned int count = 0;
  for(unsigned int  i=0; i<N; ++i)
    {
      const auto x= dis(gen);
      const auto y= dis(gen);
      // if( (x*x + y*y)<1. )
	{
	  count += ( (x*x + y*y)<1. );
	  if(verbose)
	    {
	      cout<<i<<"\t"<<count<<"\t"<<x<<"\t"<<y<<endl;
	    }
	  if(N_evolution && i%N_evolution ==0)
	    {
	      const double pi = 4.*((double) count)/i;
	      if(outfile_b)
		{
		  outfile<<i<<"\t"<<pi<<endl;
		}
	      else
		{
		  cout<<i<<"\t"<<pi<<endl;
		}
	    }
	}
    }
  const double pi = 4.*((double) count)/N;
  cout<<"My estimation of pi is: "<< pi <<endl;

  if(outfile_b)
    {
      outfile.close();
    }
  
  return 0;  
}
