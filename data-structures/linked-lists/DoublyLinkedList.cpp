/*
  Data Structures | Doubly-Linked List

  This doubly-linked list will only cover `int` data types.

  ---- Time Complexities  ----
  | Append at head    | O(1) |
  | Append at tail    | O(1) |
  | Insert at index i | O(n) |
  | Delete at head    | O(1) |
  | Delete at tail    | O(1) |
  | Delete at index i | O(n) |
  | Search            | O(n) |
  | Access head       | O(1) |
  | Access tail       | O(1) |
  | Access index i    | O(n) |
  ----------------------------
*/

#include <iostream>
#include <cassert>

class Node
{
public:
  int data;
  Node *nextPtr;
  Node *previousPtr;

  Node(int data)
  {
    this->data = data;
    this->nextPtr = nullptr;
    this->previousPtr = nullptr;
  }

  Node(int data, Node *nextPtr, Node *previousPtr)
  {
    this->data = data;
    this->nextPtr = nextPtr;
    this->previousPtr = previousPtr;
  }
};

class DoublyLinkedList
{
private:
  typedef unsigned int uint;
  Node *_headPtr;
  Node *_tailPtr;
  uint _size;
  bool _isIndexOutOfBounds(uint index) { return index < 0 || index >= this->_size; }

public:
  uint size() { return this->_size; }
  bool empty() { return this->_size == 0; }

  DoublyLinkedList()
  {
    this->_headPtr = nullptr;
    this->_tailPtr = nullptr;
    this->_size = 0;
  }

  void append(int data)
  {
    auto *newNodePtr = new Node(data);
    if (this->empty())
    {
      this->_headPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    }
    else
    {
      this->_tailPtr->nextPtr = newNodePtr;
      newNodePtr->previousPtr = this->_tailPtr;
      this->_tailPtr = newNodePtr;
    }
    this->_size++;
  }

  void prepend(int data)
  {
    auto *newNodePtr = new Node(data);
    if (this->empty())
    {
      this->_headPtr = newNodePtr;
      this->_tailPtr = newNodePtr;
    }
    else
    {
      this->_headPtr->previousPtr = newNodePtr;
      newNodePtr->nextPtr = this->_headPtr;
      this->_headPtr = newNodePtr;
    }
    this->_size++;
  }

  void insertAt(uint index, int data)
  {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    else if (index == 0) this->prepend(data);
    else if (index == this->_size - 1) this->append(data);
    else
    {
      auto *newNodePtr = new Node(data);
      auto *traversalPtr = this->_headPtr;
      uint i = 0;
      while (i != index)
      {
        traversalPtr = traversalPtr->nextPtr;
        i++;
      }
      newNodePtr->nextPtr = traversalPtr;
      newNodePtr->previousPtr = traversalPtr->previousPtr;
      traversalPtr->previousPtr->nextPtr = newNodePtr;
      traversalPtr->previousPtr = newNodePtr;
      this->_size++;
    }
  }

  void removeHead()
  {
    if (this->empty()) throw std::runtime_error("List is empty.");
    auto *tempNodePtr = this->_headPtr;
    this->_headPtr = this->_headPtr->nextPtr;
    this->_headPtr->previousPtr = nullptr;
    delete tempNodePtr;
    this->_size--;
  }

  void removeTail()
  {
    if (this->empty()) throw std::runtime_error("List is empty.");
    auto *tempNodePtr = this->_tailPtr;
    this->_tailPtr = this->_tailPtr->previousPtr;
    this->_tailPtr->nextPtr = nullptr;
    delete tempNodePtr;
    this->_size--;
  }

  void removeAt(uint index)
  {
    if (this->empty()) throw std::runtime_error("List is empty.");
    else if (index == 0) this->removeHead();
    else if (index == this->_size - 1) this->removeTail();
    else
    {
      auto *traversalPtr = this->_headPtr;
      uint i = 0;
      while (i != index)
      {
        traversalPtr = traversalPtr->nextPtr;
        i++;
      }
      traversalPtr->previousPtr->nextPtr = traversalPtr->nextPtr;
      traversalPtr->nextPtr->previousPtr = traversalPtr->previousPtr;
      delete traversalPtr;
      this->_size--;
    }
  }

  int atHead()
  {
    if (this->empty()) throw std::runtime_error("List is empty.");
    return this->_headPtr->data;
  }

  int atTail()
  {
    if (this->empty()) throw std::runtime_error("List is empty.");
    return this->_tailPtr->data;
  }

  int at(uint index)
  {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    else if (index == 0) return this->atHead();
    else if (index == this->_size - 1) return this->atTail();
    auto *traversalPtr = this->_headPtr;
    uint i = 0;
    while (i != index)
    {
      traversalPtr = traversalPtr->nextPtr;
      i++;
    }
    return traversalPtr->data;
  }

  void toString()
  {
    auto *traversalPtr = this->_headPtr;
    while (traversalPtr->nextPtr != nullptr)
    {
      std::cout << traversalPtr->data << " <-> ";
      traversalPtr = traversalPtr->nextPtr;
    }
    std::cout << traversalPtr->data << " -> null" << std::endl;
    std::cout << "Head: " << this->_headPtr->data << std::endl;
    std::cout << "Tail: " << this->_tailPtr->data << std::endl;
    std::cout << "Size: " << this->_size << std::endl;
  }
};

int main()
{
  DoublyLinkedList list;

  list.append(10);
  list.append(11);
  list.insertAt(list.size() - 1, 12);
  list.prepend(9);
  list.prepend(8);
  list.insertAt(0, 7);
  list.insertAt(1, 55);

  assert(list.at(0) == 7);
  assert(list.at(1) == 55);
  assert(list.at(list.size() - 1) == 12);

  assert(list.atHead() == 7);
  assert(list.atTail() == 12);

  list.toString();

  list.removeHead();
  list.removeAt(0);
  list.removeAt(1);
  list.toString();

  return 0;
}
