#include "PriorityQueue.h"
#include <vector>
#include <iostream>
#include <climits>

PriorityQueue::PriorityQueue()
{
  heap.push_back(INT_MAX);
}

PriorityQueue::PriorityQueue(const std::vector<int> & input)
{
  // if the inputs first element isn't 0, add it
  if (input[0] != INT_MAX)
    heap.push_back(INT_MAX);
  for (auto & input_element : input)
  {
    this->Insert(input_element); 
  }
}

void PriorityQueue::HeapValueSwap(int first_index, int second_index)
{
  // < 1 since the first value in the heap is a dummy
  if (first_index < 1 || first_index >= heap.size())
    throw std::invalid_argument("First index out of range");
  if (second_index < 1 || second_index >= heap.size())
    throw std::invalid_argument("Second index out of range");

  int temp = heap[first_index];
  heap[first_index] = heap[second_index];
  heap[second_index] = temp;
}

void PriorityQueue::Insert(int new_val)
{
  // add the new value to the end of the heap
  heap.push_back(new_val);
  int new_index = heap.size() - 1;
  int parent_index = Parent(new_index);

  // maintain heap property
  while (new_val > heap[parent_index] && new_index > 1)
  {
    HeapValueSwap(new_index, parent_index);
    new_index = parent_index;
    parent_index = Parent(parent_index);
  }
}

int PriorityQueue::RemoveMax()
{
  int max_val = heap[1];
  HeapValueSwap(1, heap.size()-1);
  heap.pop_back();
  int current_index = 1;
  
  int max_child;
  while (LeftChild(current_index) < heap.size())
  {
    if (RightChild(current_index) >= heap.size())
      max_child = LeftChild(current_index);
    else
    {
      max_child = heap[RightChild(current_index)] >
        heap[LeftChild(current_index)] ? RightChild(current_index) :
        LeftChild(current_index);
    }
    if (heap[max_child] > heap[current_index])
    {
      HeapValueSwap(max_child, current_index);
      current_index = max_child; 
    }
    else
      break;
  }
  return max_val;
}

void PriorityQueue::PrintQueue(std::ostream& out)
{
  for (int i = 1; i < heap.size(); i++)
  {
    out << heap[i] << " ";
    if (i % 10 == 0)
      out << std::endl;
  }
}
