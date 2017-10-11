#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include <ctime>
#include <cstdlib>

int main()
{
  std::vector<int> input;
  srand(time(NULL));
  for (int i = 0; i < 8; i++)
  {
    //input.push_back(rand() % 30 + 1);
    //std::cout << input[i] << " ";
    input.push_back(i+1);
  }
  
  PriorityQueue pQ(input);
  pQ.PrintQueue(std::cout);
  for (int i = 0; i < 4; i++)
  {
    std::cout << pQ.RemoveMax() << std::endl;
    pQ.PrintQueue(std::cout); std::cout << std::endl;
  }
  return 0;
}
