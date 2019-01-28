#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include "s32bit.h"



int main ()
{
  std::cout << "Hello World!" << std::endl;

  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(-1, 1);

  std::map<int, float> _hist;
  std::list<float> hist;

  // so what we want to do here is
  // a) generate a bunch of random floats
  // b) assign 'em to the union's float
  // c) print out the bits & the float
  // d) manipulate the bit field
  // e) print 'em out again ...
  
  for (int n = 0; n < 10000; ++n) {
    //++hist[dist(e2)];
    //std::cout << hist[n] << std::endl;
    hist.push_front(dist(e2));
  }


  std::map<const int, float>::iterator _it = _hist.begin();

  std::list<float>::iterator it = hist.begin();
  
  // Iterate over the map using Iterator till end.
  while (it != hist.end())
    {
      std::cout<<(*it)<<std::endl;
      // Increment the Iterator to point to next entry
      it++;
    }
  
  
  return 0;
}
