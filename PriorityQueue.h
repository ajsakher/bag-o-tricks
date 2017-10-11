#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <climits>
#include <vector>
#include <iostream>
// Implementation of a priority queue using a heap
class PriorityQueue
{
  public:
    PriorityQueue();
    PriorityQueue(const std::vector<int>&);
    
    void Insert(int new_val); // inserting a new value
    int RemoveMax();  // removing the current max, returns what was removed
    void PrintQueue(std::ostream&);
  private:
    // inline functions for finding children/parent indices
    int LeftChild(int n) { return 2*n; }
    int RightChild(int n) { return 2*n + 1; }
    int Parent(int n) { return n/2; }

    void HeapValueSwap(int, int);
    std::vector<int> heap;
};

#endif
