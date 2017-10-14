#include <iostream>
#include <functional>
#include "PriorityQueueTemplate.h"

int main()
{
  std::vector<int> input;
  for (int i = 8; i > 0; i--)
  {
    input.push_back(i);
  }

  PriorityQueue<int> pQ(input, [](int a, int b) -> bool { return a < b; });
  pQ.PrintQueue(std::cout);
}
