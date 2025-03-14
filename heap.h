#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  // Ary-ness of heap
  int m_; 
  // Vector to store data
  std::vector<T> data;
  // Comparator functor
  PComparator comp;

  // Helper functions for push and pop
  void heapifyUp(int x);
  void heapifyDown(int x);
};

// Add implementation of member functions here
// Constructor with initialization list
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_(m), comp(c), 
data(){}

// Empty destructor
template <typename T, typename PComparator>
Heap<T, PComparator>:: ~Heap(){}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Empty Heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Empty Heap");
  }
  // Switch first and last, then pop last, then ensure heap structure
  data[0] = data.back();
  data.pop_back();
  heapifyDown(0);
}
template <typename T, typename PComparator>
// Returns true if heap is empty
bool Heap<T, PComparator>::empty() const
{
  return (data.size() == 0);
}
// Push function adds to first available opening, then heapifys up
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  data.push_back(item);
  heapifyUp(data.size() - 1);
}
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data.size();
}

// Helper functions

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int x)
{
  // Base case at root
  if (x == 0)
  {
    return;
  }
  // Recursive step, swapping up as needed
  if (comp(data[x], data[(x-1)/m_]))
  {
    std::swap(data[x], data[(x-1)/m_]);
    heapifyUp((x-1)/m_);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int x)
{
  // Initialize variables for iteration
  int size = data.size();
  int bestNode = x;
  // Loop through indexes children, finding best one
  for (size_t i =  m_*x +1; i < m_*x + m_ + 1&& i < size; ++i)
  {
    if (comp(data[i], data[bestNode]))
    {
      bestNode = i;
    }
  }
  // If there is a better one than x, swap x with the best one, and
  // recurse
  if (bestNode != x)
  {
    std::swap(data[x], data[bestNode]);
    heapifyDown(bestNode);
  }
}
 
#endif

