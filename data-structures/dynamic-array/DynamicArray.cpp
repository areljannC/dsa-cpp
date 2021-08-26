/*
  Data Structures | Dynamic Array

  This dynamic array implementation will only cover `int` data types.

  ---    Time Complexities     ---
  | Append                | O(1) |
  | Append (expand array) | O(n) |
  | Insert at index i     | O(n) |
  | Delete at index i     | O(n) |
  | Search                | O(n) |
  | Access index i        | O(1) |
  --------------------------------
*/

#include <iostream>
#include <cassert>

class DynamicArray {
private:
  typedef unsigned int uint;
  int *_arrayPtr;
  uint _size;
  uint _capacity;
  uint _initialCapacity;
  bool _shouldIncreaseCapacity() { return this->_size <= this->_capacity && this->_size + 1 > this->_capacity; }
  bool _shouldDecreaseCapacity() { return this->_size - 1 == this->_capacity / 2; }
  bool _isIndexOutOfBounds(int index) { return index < 0 || index >= this->_size; }

public:
  uint size() { return this->_size; }
  bool empty() { return this->_size == 0; }

  DynamicArray() {
    this->_arrayPtr = new int[0];
    this->_size = 0;
    this->_capacity = 0;
    this->_initialCapacity = 0;
  }

  DynamicArray(uint capacity) {
    this->_arrayPtr = new int[capacity];
    this->_size = 0;
    this->_capacity = 0;
    this->_initialCapacity = capacity;
  }

  void append(int element) {
    if (this->_shouldIncreaseCapacity()) this->increaseCapacity();
    this->_arrayPtr[this->_size++] = element;
  }

  void insert_at(uint index, uint element) {
    if (this->_shouldIncreaseCapacity()) this->increaseCapacity();
    for (uint i = this->_capacity - 1; i > index; i--) this->_arrayPtr[i] = this->_arrayPtr[i-1];

    this->_arrayPtr[index] = element;
    this->_size++;
  }

  void delete_at(uint index) {
    if (this->_shouldDecreaseCapacity()) this->decreaseCapacity();
    for (uint i = index; i < this->_size; i++) this->_arrayPtr[i] = this->_arrayPtr[i+1];
    this->_size--;
  }

  int at(uint index) {
    if (this->_isIndexOutOfBounds(index)) throw std::out_of_range("Index is out of bounds.");
    return this->_arrayPtr[index];
  }

  void increaseCapacity() {
    if (this->_capacity == 0) this->_capacity = 1;
    else this->_capacity *= 2;

    auto tempArrayPtr = new int[this->_capacity];
    for (uint i = 0; i < this->_size; i++) tempArrayPtr[i] = this->_arrayPtr[i];

    delete[] this->_arrayPtr;
    this->_arrayPtr = tempArrayPtr;
  }

  void decreaseCapacity() {
    this->_capacity /= 2;
    if (this->_capacity < this->_initialCapacity) this->_capacity = this->_initialCapacity;

    auto tempArrayPtr = new int[this->_capacity];
    for (uint i = 0; i < this->_size; i++) tempArrayPtr[i] = this->_arrayPtr[i];

    delete[] this->_arrayPtr;
    this->_arrayPtr = tempArrayPtr;
  }

  void toString() {
    std::cout << "[";
    for (uint i = 0; i < this->_size; i++) {
      if (i == this->_size - 1) std::cout << this->_arrayPtr[i];
      else std::cout << this->_arrayPtr[i] << ", ";
    }
    std::cout << "]" <<  std::endl;

    std::cout << "Size: " << this->_size << std::endl;
    std::cout << "Capacity: " << this->_capacity << std::endl;
    std::cout << "Initial Capacity: " << this->_initialCapacity << std::endl;
  }
};

int main() {
  DynamicArray arr(2);
  
  arr.append(1);
  arr.append(2);
  arr.append(3);
  arr.append(3);
  arr.append(3);
  arr.append(3);
  arr.delete_at(0);
  arr.delete_at(0);
  arr.toString();

  return 0;
}
