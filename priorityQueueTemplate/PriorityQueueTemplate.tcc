#ifndef PRIORITY_QUEUE_T_H
#define PRIORITY_QUEUE_T_H
#include <functional>
#include <vector>
#include <iostream>

template <typename T> class PriorityQueue
{
  public:
    // constructors
    PriorityQueue();
    PriorityQueue(const std::vector<T>&, const std::function<bool(T,T)>&);

    void Insert(T new_val);
    T RemoveTop();
    void PrintQueue(std::ostream&);
  private:
    std::function<bool(T, T)> comparison;
    int LeftChild(int n) { return 2*n; }
    int RightChild(int n) { return 2*n + 1; }
    int Parent(int n) { return n/2; }
    void HeapValueSwap(int , int);

    std::vector<T> heap;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{ 
  heap.push_back(static_cast<T>(NULL));
  comparison = [](T a, T b) -> bool { return a < b; };
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const std::vector<T>& input,
             const std::function<bool(T, T)>& func)
{ 
  comparison = func;
  heap.push_back(static_cast<T>(NULL));
  for (auto & element : input)
    this->Insert(element);
}

template<typename T>
void PriorityQueue<T>::HeapValueSwap(int first_index, int second_index)
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

template<typename T>
void PriorityQueue<T>::PrintQueue(std::ostream& out)
{
  for (int i = 1; i < heap.size(); i++)
  {
    out << heap[i] << " ";
    if (i % 10 == 0)
      out << std::endl;
  }
}

template<typename T>
T PriorityQueue<T>::RemoveTop()
{
  if (heap.size() < 2)
    return nullptr;

  T max_val = heap[1];
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
      max_child = comparison(heap[RightChild(current_index)],
        heap[LeftChild(current_index)]) ? RightChild(current_index) :
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

template<typename T>
void PriorityQueue<T>::Insert(T new_val)
{
  // add the new value to the end of the heap
  heap.push_back(new_val);
  int new_index = heap.size() - 1;
  int parent_index = Parent(new_index);

  // maintain heap property
  while (comparison(new_val, heap[parent_index]) && new_index > 1)
  {
    HeapValueSwap(new_index, parent_index);
    new_index = parent_index;
    parent_index = Parent(parent_index);
  }
}

#endif
