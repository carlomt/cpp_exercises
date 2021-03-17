#include <chrono>
#include <iostream>
#include <vector>

int main()
{
  const std::vector<double> v = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  };
  
  const auto t1a = std::chrono::high_resolution_clock::now();
  for (auto& el : v)
    {
      std::cout<<el*el<<std::endl;
    }
  const auto t2a = std::chrono::high_resolution_clock::now();

  const auto t1b = std::chrono::high_resolution_clock::now();
  std::for_each(v.begin(), v.end(), [](auto& el) {  std::cout<<el*el<<std::endl; });
  const auto t2b = std::chrono::high_resolution_clock::now();
    
  /* Getting number of milliseconds as an integer. */
  auto ms_int_a = std::chrono::duration_cast<std::chrono::milliseconds>(t2a - t1a);
  auto ms_int_b = std::chrono::duration_cast<std::chrono::milliseconds>(t2b - t1b);
  
  /* Getting number of milliseconds as a double. */
  std::chrono::duration<double, std::milli> ms_double_a = t2a - t1a;
  std::chrono::duration<double, std::milli> ms_double_b = t2b - t1b;
  
  std::cout << ms_int_a.count() << "ms\n";
  std::cout << ms_double_a.count() << "ms" <<std::endl;
  std::cout << ms_int_b.count() << "ms\n";
  std::cout << ms_double_b.count() << "ms";
  return 0;
  
}
