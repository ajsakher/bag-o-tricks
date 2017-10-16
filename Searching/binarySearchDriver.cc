#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "binarySearch.h"

int main()
{

  srand(time(NULL));

  std::vector<int> input;
  for (int i = 1; i < 100000000; i++)
  {
    input.push_back(i);
  }
  
  int find = (rand() % 100000000) + 1;
  int index = BinarySearch<int>(input, find);
  std::cout << find << " found at index: " << index << std::endl;
  return 0;
}
