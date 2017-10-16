// binary search implementation
#include <iostream>
#include <vector>
#include <functional>

// assumption made that input is sorted
template<typename T>
int BinarySearch(const std::vector<T>& input, T find,
    const std::function<bool(T a, T b)>& lessThan = [] (T a, T b) -> bool { return a < b; })
{
  int left = 0; // left end of current search interval
  int right = input.size() - 1;  // right end of current search interval
  int current = (left + right)/2;
  while (left < current && right > current)
  {
    // check if we found it
    if (input[current] == find)
      return current;
    else if (lessThan(input[current], find))
      left = current;  // look at right interval next
    else
      right = current;  // look at left interval next

    // find new evaluation point
    current = (left + right)/2;
  }
  return -1;
}
