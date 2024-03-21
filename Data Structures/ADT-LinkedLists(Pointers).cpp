#include <iostream>

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class LinkedList {
private:
  Node* head;

public:
  // Constructor
  LinkedList() {
    head = nullptr;
  }

  // 1. INSERT(x, p, L)
  void insert(int x, int p) {
    Node* newNode = new Node(x);

    // Insert at the beginning (p == 0)
    if (p == 0) {
      newNode->next = head;
      head = newNode;
      return;
    }

    // Find the node at position p-1
    Node* current = head;
    int i = 0;
    while (current != nullptr && i < p - 1) {
      current = current->next;
      i++;
    }

    // Check if position p exists
    if (current == nullptr) {
      return; // undefined behavior for invalid position
    }

    // Insert at the end (p == END(L))
    if (current->next == nullptr) {
      current->next = newNode;
      return;
    }

    // Insert in the middle
    newNode->next = current->next;
    current->next = newNode;
  }

  // 2. LOCATE(x, L)
  int locate(int x) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
      if (current->data == x) {
        return position;
      }
      current = current->next;
      position++;
    }
    return -1; // x not found
  }

  // 3. RETRIEVE(p, L)
  int retrieve(int p) {
    Node* current = head;
    int i = 0;
    while (current != nullptr && i < p) {
      current = current->next;
      i++;
    }

    // Check if position p exists
    if (current == nullptr) {
      // undefined behavior for invalid position
      throw std::out_of_range("Invalid position");
    }

    return current->data;
  }

  // 4. DELETE(p, L)
  void deleteNode(int p) {
    // Handle deletion at the beginning
    if (p == 0) {
      head = head->next;
      return;
    }

    // Find the node at position p-1
    Node* current = head;
    int i = 0;
    while (current != nullptr && i < p - 1) {
      current = current->next;
      i++;
    }

    // Check if position p exists
    if (current == nullptr || current->next == nullptr) {
      return; // undefined behavior for invalid position
    }

    // Delete the node at position p
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
  }

  // 5. NEXT(p, L) and PREVIOUS(p, L)
  int next(int p) {
    Node* current = head;
    int i = 0;
    while (current != nullptr && i < p) {
      current = current->next;
      i++;
    }

    // Check if position p exists
    if (current == nullptr) {
      return -1; // undefined behavior for invalid position
    }

    return (current->next != nullptr) ? i + 1 : -1;
  }

  int previous(int p) {
    if (p == 0) {
      return -1; // undefined behavior for p = 0
    }

    Node* current = head;
    int i = 0;
    while (current != nullptr && i < p - 1) {
      current = current->next;
      i++;
    }

    // Check if position p exists
    if (current == nullptr) {
      return -1; // undefined behavior for invalid position
    }

    return i;
  }

  // 6. MAKENULL(L)
  void makeNull() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  // 7. FIRST(L)
  int first() {
    if (head == nullptr) {
      return -1; // List is empty
    }
    return head->data;
  }

  // 8. PRINTLIST(L)
  void printList() {
    Node* current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // 9. END(L)
  int end() {
    if (head == nullptr) {
      return -1; // List is empty
    }

    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    return locate(current->data); // Return position of the last element
  }

  // 10. SIZE(L)
  int size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    return count;
  }
};

int main() {
  
  return 0;
}
