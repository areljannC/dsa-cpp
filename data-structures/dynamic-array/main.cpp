/* Data Structure | Dynamic Array */

#include <iostream>

template <typename T>
class DynamicArray
{
private:
  T *arrayPtr;
  int initialCapacity;

public:
  int capacity;
  int length;

  DynamicArray()
  {
    this->arrayPtr = new T[0];
    this->length = 0;
    this->capacity = 0;
    this->initialCapacity = 0;
  }

  DynamicArray(int capacity)
  {
    if (capacity < 0)
    {
      throw std::out_of_range("Initial capacity cannot be negative.");
    }
    this->arrayPtr = new T[capacity];
    this->length = 0;
    this->capacity = capacity;
    this->initialCapacity = capacity;
  }

  int size() { return this->length; }
  bool isEmpty() { return this->length == 0; }

  void append(T element)
  {
    // Check if `capacity` == 0.
    if (this->capacity == 0)
    {
      this->capacity = 1;
    }

    // Check if appending an element is > `capacity`.
    if (this->length + 1 > capacity)
    {
      // Create a new array with double the size.
      this->capacity *= 2;
      T *newArrayPtr = new T[this->capacity];

      // Copy elements to new array.
      for (register int i = 0; i < this->length; i++)
      {
        newArrayPtr[i] = this->arrayPtr[i];
      }

      // Free up memory.
      delete[] this->arrayPtr;

      // Append new to element to new array.
      newArrayPtr[this->length] = element;
      this->length++;
      this->arrayPtr = newArrayPtr;
    }
    else
    {
      this->arrayPtr[this->length] = element;
      this->length++;
    }
  }

  void remove()
  {
    if (this->length - 1 < 0)
    {
      throw std::out_of_range("Array is already empty.");
    }
    else
    {
      this->arrayPtr[this->length] = 0;
      this->length--;
    }
  }

  void removeAt(int index)
  {
    if (index > this->capacity || index < 0 || index > this->length)
    {
      throw std::out_of_range("Index is out of bounds.");
    }
    else
    {
      for (register int i = index; i < this->length - 1; i++)
      {
        this->arrayPtr[i] = this->arrayPtr[i + 1];
      }
      this->arrayPtr[this->length] = 0;
      this->length--;
    }
  }

  T get(int index)
  {
    if (index > this->capacity || index < 0)
    {
      throw std::out_of_range("Index is out of bounds.");
    }
    else
    {
      return this->arrayPtr[index];
    }
  }

  void set(int index, T element)
  {
    if (index > this->capacity || index < 0 || index > this->length)
    {
      throw std::out_of_range("Index is out of bounds.");
    }
    else
    {
      if (index == this->length)
      {
        this->length++;
      }
      this->arrayPtr[index] = element;
    }
  }

  bool contains(T element)
  {
    for (register int i = 0; i < this->length; i++)
    {
      if (this->arrayPtr[i] == element)
      {
        return true;
      }
    }
    return false;
  }

  int indexOf(T element)
  {
    for (register int i = 0; i < this->length; i++)
    {
      if (this->arrayPtr[i] == element)
      {
        return i;
      }
    }
    return -1;
  }

  void clear()
  {
    // Set array elements to 0.
    for (register int i = 0; i < this->length; i++)
    {
      this->arrayPtr[i] = 0;
    }

    // Set `length` back to 0.
    this->length = 0;

    // Create new array with a size of the initial capacity.
    delete[] this->arrayPtr;
    T *newArrayPtr = new T[this->initialCapacity];
    this->capacity = this->initialCapacity;
    this->arrayPtr = newArrayPtr;
  }

  void toString()
  {
    if (this->length == 0)
    {
      std::cout << "[]" << std::endl;
    }
    else
    {
      std::cout << "[";
      for (register int i = 0; i < this->length; i++)
      {
        if (i != this->length - 1)
        {
          std::cout << this->arrayPtr[i] << ", ";
        }
        else
        {
          std::cout << this->arrayPtr[i];
        }
      }
      std::cout << "]" << std::endl;
    }
  }
};

// TO DO: Add test cases.