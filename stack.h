#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
// Private inheritance, becuase methods will just be helper functions
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
// Implemented stack methods
template <typename T>
Stack<T>:: Stack(): std::vector<T>()
{
}
template <typename T>
Stack<T>:: ~Stack()
{
}

template <typename T>
bool Stack<T>::empty() const
{
    return this->std::vector<T>::empty();

}
template <typename T>
size_t Stack<T>::size() const
{
    return this->std::vector<T>::size();
}
template <typename T>
void Stack<T>::push(const T& item)
{
    this->std::vector<T>::push_back(item);
}
template <typename T>
void Stack<T>::pop()
{
    if (this->empty())
    {
        throw std::underflow_error("Empty Stack");
    }
    else{
        this->std::vector<T>::pop_back();
    }
}
template <typename T>
const T& Stack<T>::top() const
{
    if (this->empty())
    {
        throw std::underflow_error("Empty Stack");
    }
    else
    {
        return this-> std::vector<T>::back();
    }
}
#endif