/*
  Data Structures | Stack (Static Array)

  This stack implementation will only cover `int` data types.

  --- Time Complexities ---
  | Push           | O(1) |
  | Pop            | O(1) |
  | Peek           | O(1) |
  | Search         | O(n) |
  -------------------------
*/

#include <iostream>
#include <cassert>

class StackStaticArray
{
private:
  typedef unsigned int uint;
  int *_arrayPtr;
  uint _size;
  uint _capacity;
  bool _isFull() { return this->_size == this->_capacity; }

public:
  uint size() { return this->_size; }
  bool empty() { return this->_size == 0; }

  StackStaticArray(uint capacity)
  {
    this->_arrayPtr = new int[capacity];
    this->_size = 0;
    this->_capacity = capacity;
  }

  void push(int element)
  {
    if (this->_isFull()) throw std::runtime_error("Stack is full.");
    this->_arrayPtr[this->_size++] = element;
  }

  int pop()
  {
    if (this->empty()) throw std::runtime_error("Stack is empty.");
    return this->_arrayPtr[this->_size-- - 1];
  }

  int top()
  {
    if (this->empty()) throw std::runtime_error("Stack is empty.");
    return this->_arrayPtr[this->_size - 1];
  }

  bool contains(int element)
  {
    if (this->empty()) throw std::runtime_error("Stack is empty.");
    for (uint i = 0; i < this->_size; i++) if (this->_arrayPtr[i] == element) return true;
    return false;
  }

  int indexOf(int element)
  {
    if (this->empty()) throw std::runtime_error("Stack is empty.");
    for (uint i = 0; i < this->_size; i++) if (this->_arrayPtr[i] == element) return i;
    return -1;
  }

  void toString()
  {
    for (uint i = 0; i < this->_size; i++)
    {
      if (i == this->_size - 1) std::cout << this->_arrayPtr[i];
      else std::cout << this->_arrayPtr[i] << " -> ";
    }
    std::cout << std::endl;
    std::cout << "Top: " << this->top() << std::endl;
    std::cout << "Size: " << this->_size << std::endl;
    std::cout << "Capacity: " << this->_capacity << std::endl;
  }
};

int main()
{
  StackStaticArray stack(4);

  stack.push(1);
  stack.push(2);

  assert(stack.top() == 2);
  assert(stack.size() == 2);

  stack.push(3);
  stack.push(4);

  assert(stack.top() == 4);
  assert(stack.size() == 4);

  assert(stack.pop() == 4);
  assert(stack.pop() == 3);

  assert(stack.top() == 2);
  assert(stack.size() == 2);

  assert(stack.contains(1) == true);
  assert(stack.contains(2) == true);
  assert(stack.contains(3) == false);

  assert(stack.indexOf(1) == 0);
  assert(stack.indexOf(2) == 1);
  assert(stack.indexOf(3) == -1);

  stack.toString();

  return 0;
}
