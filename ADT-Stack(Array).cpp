#include <iostream>
#include <stdexcept> // for std::out_of_range
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
  int arr[MAX_SIZE]; // Array to store elements of the stack
  int top; // Index of the top element of the stack

public:
  // Constructor
  Stack() {
    top = -1; // Initialize top to -1 (indicating an empty stack)
  }

  // Method to push an element onto the stack
  void push(int element) {
    if (top == MAX_SIZE - 1) { // Check if stack is full
      throw out_of_range("Unable to push item, stack full!");
    }
    top++; // Move the top pointer up
    arr[top] = element; // Add the element to the top of the stack
  }

  // Method to pop an element from the stack
  int pop() {
    if (top == -1) { // Check if stack is empty
      throw out_of_range("Unable to pop item, stack empty!");
    }
    int poppedElement = arr[top]; // Store the top element
    top--; // Move the top pointer down
    return poppedElement; // Return the popped element
  }

  // Method to check if the stack is empty
  bool isEmpty() {
    return (top == -1); // Stack is empty if top is -1
  }
};

int main() {
  // Let's test our array-based stack ADT
  Stack myStack;

  myStack.push(5);
  myStack.push(10);
  myStack.push(15);

  cout << "Popping elements from the stack:" << endl;
  while (!myStack.isEmpty()) {
    cout << myStack.pop() << " ";
  }
  cout << endl;

  return 0;
}
