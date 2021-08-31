/*
  Data Structures | Singly-Linked List

  This singly-linked list will only cover `int` data types.

  --- Time Complexities ---
  | Append at head    | O(1)
  | Append at tail    | O(1)
  | Insert at index i | O(n)
  | Delete at head    | O(1)
  | Delete at tail    | O(1)
  | Delete at index i | O(n)
  | Search            | O(n)
  | Access head       | O(1)
  | Access tail       | O(1)
  | Access index i    | O(n)
*/

#include <iostream>
#include <cassert>

class Node {
public:
  int data;
  Node *nextPtr;

  Node(int data) {
    this->data = data;
    this->nextPtr = nullptr;
  }

  Node(int data, Node *nextPtr) {
    this->data = data;
    this->nextPtr = nextPtr;
  }
};

class SinglyLinkedList {
private:
  typedef unsigned int uint;
  Node *_headPtr;
  Node *_tailPtr;
  uint _size;
  bool _isIndexOutOfBounds(uint index) { return index < 0 || index >= this->_size; }

public:
  uint size() { return this->_size; }
  bool empty() { return this->_size == 0; }

  SinglyLinkedList() {
    this->_headPtr = nullptr;
    this->_tailPtr = nullptr;
    this->_size = 0;
  }

  void append(int data) {
    auto *newNodePtr = new Node(data);
    if (this->_size == 0) {
      this->_headPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    } else {
      this->_tailPtr->nextPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    }
    this->_size++;
  }

  void prepend(int data) {
    auto *newNodePtr = new Node(data);
    if (this->_size == 0) {
      this->_headPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    } else {
      newNodePtr->nextPtr = this->_headPtr;
      this->_headPtr = newNodePtr;
    }
    this->_size++;
  }
  
  void insertAt(uint index, int data) {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    if (index == 0) this->prepend(data);
    else {
      auto *newNodePtr = new Node(data);
      auto *traversalPtr = this->_headPtr;
      uint i = 0;
      while (i+1 != index) {
        traversalPtr = traversalPtr->nextPtr;
        i++;
      }
      newNodePtr->nextPtr = traversalPtr->nextPtr;
      traversalPtr->nextPtr = newNodePtr;
      this->_size++;
    }
  }

  void removeHead() {
    if (this->_size == 0) throw std::runtime_error("List is empty.");
    auto *tempNodePtr = this->_headPtr->nextPtr;
    delete this->_headPtr;
    this->_headPtr = tempNodePtr;
    this->_size--;
  }

  void removeTail() {
    if (this->_size == 0) throw std::runtime_error("List is empty.");
    auto *traversalPtr = this->_headPtr;
    while (traversalPtr->nextPtr != this->_tailPtr) traversalPtr = traversalPtr->nextPtr;
    delete this->_tailPtr;
    this->_tailPtr = traversalPtr;
    this->_tailPtr->nextPtr = nullptr;
    this->_size--;
  }

  void removeAt(int index) {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    else if (index == 0) this->removeHead();
    else if (index == this->_size - 1) this->removeTail();
    else {
      auto *traversalPtr = this->_headPtr;
      int i = 0;
      while (i+1 != index) {
        traversalPtr = traversalPtr->nextPtr;
        i++;
      }
      auto *tempNodePtr = traversalPtr->nextPtr->nextPtr;
      delete traversalPtr->nextPtr;
      traversalPtr->nextPtr = tempNodePtr;
      this->_size--;
    }
  }

  int atHead() {
    if (this->_size == 0) throw std::runtime_error("List is empty.");
    return this->_headPtr->data;
  }

  int atTail() {
    if (this->_size == 0) throw std::runtime_error("List is empty.");
    return this->_tailPtr->data;
  }

  int at(uint index) {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    auto *traversalPtr = this->_headPtr;
    int i = 0;
    while (i != index) {
      traversalPtr = traversalPtr->nextPtr;
      i++;
    }
    return traversalPtr->data;
  }

  void toString() {
    auto *traversalPtr = this->_headPtr;
    while (traversalPtr->nextPtr != nullptr) {
      std::cout << traversalPtr->data << " -> ";
      traversalPtr = traversalPtr->nextPtr;
    }
    std::cout << traversalPtr->data << " -> null" << std::endl;
    std::cout << "Head: " << this->_headPtr->data << std::endl;
    std::cout << "Tail: " << this->_tailPtr->data << std::endl;
    std::cout << "Size: " << this->_size << std::endl;
  }
};

int main() {
  SinglyLinkedList list;

  list.append(0);
  list.append(1);
  list.prepend(99);
  list.prepend(5);
  list.insertAt(2, 55);
  list.removeHead();
  list.removeTail();
  list.removeAt(1);
  list.toString();

  assert(list.at(0) == 99);
  assert(list.at(1) == 0);
  assert(list.atHead() == 99);
  assert(list.atTail() == 0);

  return 0;
}
