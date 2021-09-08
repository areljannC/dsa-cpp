/*
  Data Structures | Stack (Doubly-Linked List)

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

class Node {
public:
  int data;
  Node *nextPtr;
  Node *previousPtr;

  Node(int data) {
    this->data = data;
    this->nextPtr = nullptr;
    this->previousPtr = nullptr;
  }

  Node(int data, Node *nextPtr, Node *previousPtr) {
    this->data = data;
    this->nextPtr = nextPtr;
    this->previousPtr = previousPtr;
  }
};

class StackLinkedList {
private:
  typedef unsigned int uint;
  Node *_headPtr;
  Node *_tailPtr;
  uint _size;

public:
  uint size() { return this->_size; }
  bool empty() { return this->_size == 0; }

  StackLinkedList() {
    this->_headPtr = nullptr;
    this->_tailPtr = nullptr;
    this->_size = 0;
  }

  void push(int data) {
    auto *newNodePtr = new Node(data);
    if (this->empty()) {
      this->_headPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    } else {
      this->_tailPtr->nextPtr = newNodePtr;
      newNodePtr->previousPtr = this->_tailPtr;
      this->_tailPtr = newNodePtr;
    }
    this->_size++;
  }

  void pop() {
    if (this->empty()) throw std::runtime_error("List is empty.");
    auto *tempNodePtr = this->_tailPtr;
    if (this->_tailPtr->previousPtr == nullptr) {
      this->_tailPtr = nullptr;
      this->_headPtr = nullptr;
    } else {
      this->_tailPtr = this->_tailPtr->previousPtr;
      this->_tailPtr->nextPtr = nullptr;
    }
    delete tempNodePtr;
    this->_size--;
  }

  int top() {
    if (this->empty()) throw std::runtime_error("List is empty.");
    return this->_tailPtr->data;
  }

  void toString() {
    if (this->empty()) std::cout << "List is empty." << std::endl;
    else {
      auto *traversalPtr = this->_headPtr;
      while (traversalPtr != nullptr) {
        if (traversalPtr->nextPtr == nullptr) std::cout << traversalPtr->data;
        else std::cout << traversalPtr->data << " -> ";
        traversalPtr = traversalPtr->nextPtr;
      }
      std::cout << std::endl;

      std::cout << "Top: " << this->_headPtr->data << std::endl;
      std::cout << "Size: " << this->_size << std::endl;
    }
  }
};

int main() {
  StackLinkedList stack;

  stack.push(1);
  assert(stack.top() == 1);

  stack.push(2);
  assert(stack.top() == 2);

  stack.pop();
  assert(stack.top() == 1);

  stack.pop();

  stack.toString();

  return 0;
}
