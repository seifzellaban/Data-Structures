#include <iostream>
using std::cout, std::endl, std::string;

class Array {
  int* ptr;
  int size;
  int length; // Current length of the array

public:
  Array(int arrSize) {
    ptr = new int[arrSize]; // Create the array in heap
    size = arrSize;
    length = 0;
  }

  int getSize() {
    return size;
  }

  int getLength() {
    return length;
  }

  void display() {
    if (length == 0) {
      cout << "Array is empty." << endl;
      return;
    }
    cout << "Elements of the array: ";
    for (int i = 0; i < length; i++) {
      cout << ptr[i] << " ";
    }
    cout << endl;
  }

  void append(int x) {
    if (length < size) {
      ptr[length] = x;
      length++;
      return;
    }
    cout << "Unable to insert item, array full!\n";
  }

  int search(int x) {
    for (int i = 0; i < size; i++) {
      if (ptr[i] == x)
        return i;
    }
      return -1;
  }
   
};

int main() {
  Array L(6);
  L.append(5);
  L.append(10);
  L.append(69);
  int lol = L.search(13);
  cout << lol << endl;
  L.display();
  return 0;
}