/* 
  Data Structure | Singly-Linked List
  Based on this implementation by William Fiset: https://bit.ly/3rdo30E
*/

#include <iostream>

template <typename T>
class Node
{
public:
  T data;
  Node<T> *nextNodePtr;

  Node(T data, Node<T> *nextNodePtr)
  {
    this->data = data;
    this->nextNodePtr = nextNodePtr;
  }
};

template <typename T>
class SinglyLinkedList
{
private:
  Node<T> *headNodePtr;
  Node<T> *tailNodePtr;
  int sizeCount;

public:
  SinglyLinkedList()
  {
    this->headNodePtr = nullptr;
    this->tailNodePtr = nullptr;
    this->sizeCount = 0;
  }

  int size() const { return this->sizeCount; }
  bool isEmpty() const { return this->sizeCount == 0; }

  void clear()
  {
    if (this->sizeCount == 0)
    {
      throw std::runtime_error("List is already empty.");
    }
    else
    {
      Node<T> *traversalPtr = this->headNodePtr;
      while (traversalPtr != nullptr)
      {
        Node<T> *nextNodePtr = traversalPtr->nextNodePtr;
        delete traversalPtr;
        traversalPtr = nextNodePtr;
      }
      this->headNodePtr = this->tailNodePtr = nullptr;
      this->sizeCount = 0;
    }
  }

  void add(T element)
  {
    this->addLast(element);
  }

  void addFirst(T element)
  {
    if (this->isEmpty())
    {
      this->headNodePtr = this->tailNodePtr = new Node<T>(element, nullptr);
    }
    else
    {
      this->headNodePtr = new Node<T>(element, this->headNodePtr);
    }
    this->sizeCount++;
  }

  void addLast(T element)
  {
    if (this->isEmpty())
    {
      this->headNodePtr = this->tailNodePtr = new Node<T>(element, nullptr);
    }
    else
    {
      this->tailNodePtr->nextNodePtr = new Node<T>(element, nullptr);
      this->tailNodePtr = this->tailNodePtr->nextNodePtr;
    }
    this->sizeCount++;
  }

  T peekFirst()
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else
    {
      return this->headNodePtr->data;
    }
  }

  T peekLast()
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else
    {
      return this->tailNodePtr->data;
    }
  }

  T removeFirst()
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else
    {
      // Get the data of the head node.
      T data = this->headNodePtr->data;

      // Get the next node of the head node.
      Node<T> *nextNodePtr = this->headNodePtr->nextNodePtr;

      // Delete the head node.
      delete this->headNodePtr;

      // Assign the next node as the head node.
      this->headNodePtr = nextNodePtr;

      // Decrease size count.
      this->sizeCount--;

      // If list is empty, set the tail node to null.
      if (this->isEmpty())
      {
        this->tailNodePtr = nullptr;
      }

      return data;
    }
  }

  T removeLast()
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else
    {
      // Get the data of the tail node.
      T data = this->tailNodePtr->data;

      // Check if head node and tail node is the same.
      if (this->headNodePtr == this->tailNodePtr)
      {
        delete this->headNodePtr;
        this->headNodePtr = this->headNodePtr->nextNodePtr = nullptr;
        this->tailNodePtr = this->tailNodePtr->nextNodePtr = nullptr;
      }
      else
      {
        // Get the node before the tail node
        // by traversing from the head node.
        Node<T> *traversalNodePtr = this->headNodePtr;
        while (traversalNodePtr->nextNodePtr != this->tailNodePtr)
        {
          traversalNodePtr = traversalNodePtr->nextNodePtr;
        }

        // Delete the tail node.
        delete this->tailNodePtr;

        // Set the node before the
        // tail node as the tail node.
        this->tailNodePtr = traversalNodePtr;
        this->tailNodePtr->nextNodePtr = nullptr;

        // If list is empty, set the head node to null.
        if (this->isEmpty())
        {
          this->headNodePtr = nullptr;
        }
      }

      // Decrease the size count.
      this->sizeCount--;

      return data;
    }
  }

  T removeAt(int index)
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else if (index >= this->sizeCount || index < 0)
    {
      throw std::out_of_range("Index is out bounds.");
    }
    else if (index == 0)
    {
      return this->removeFirst();
    }
    else if (index == this->sizeCount - 1)
    {
      return this->removeLast();
    }
    else
    {
      // Find the node by traversing through the list.
      Node<T> *traversalNodePtr = this->headNodePtr;
      for (register int i = 0; i + 1 != index; i++)
      {
        traversalNodePtr = traversalNodePtr->nextNodePtr;
      }

      // Get the data from the node.
      T data = traversalNodePtr->nextNodePtr->data;

      // Get the node that's to be removed.
      Node<T> *deleteNodePtr = traversalNodePtr->nextNodePtr;

      // Set the current node's next node
      // to be the removed node's next node.
      traversalNodePtr->nextNodePtr = deleteNodePtr->nextNodePtr;

      // Delete the node.
      delete deleteNodePtr;
      this->sizeCount--;

      return data;
    }
  }

  void print()
  {
    if (this->isEmpty())
    {
      throw std::runtime_error("List is empty.");
    }
    else
    {
      Node<T> *traversalPtr = this->headNodePtr;
      while (traversalPtr != nullptr)
      {
        std::cout << traversalPtr->data;
        if (traversalPtr->nextNodePtr != nullptr)
        {
          std::cout << " --> ";
        }
        traversalPtr = traversalPtr->nextNodePtr;
      }
      std::cout << std::endl;
    }
  }
};
