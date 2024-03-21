#include <iostream>
using namespace std;

const int SIZE = 100;

class List {
private:
  int arr[SIZE];
  int size;
public:
  List() {
    size = 0;
  }

  void INSERT(int x, int p) {
    if (p < 0 || p > size) {
      cout << "Invalid position!\n";
      return;
    }
    for (int i = size; i > p; --i) {
      arr[i] = arr[i - 1];
    }
    arr[p] = x;
    size++;
  }

  int LOCATE(int x) {
    for (int i = 0; i < size; ++i) {
      if (arr[i] == x) {
        return i;
      }
    }
    return -1; // Not found
  }

  int RETRIEVE(int p) {
    if (p < 0 || p >= size) {
      cout << "Invalid position!\n";
      return -1; // Return undefined
    }
    return arr[p];
  }

  void DELETE(int p) {
    if (p < 0 || p >= size) {
      cout << "Invalid position!\n";
      return;
    }
    for (int i = p; i < size - 1; ++i) {
      arr[i] = arr[i + 1];
    }
    size--;
  }

  int NEXT(int p) {
    if (p < 0 || p >= size - 1) {
      cout << "Invalid position!\n";
      return -1; // Return undefined
    }
    return p + 1;
  }

  int PREVIOUS(int p) {
    if (p <= 0 || p >= size) {
      cout << "Invalid position!\n";
      return -1; // Return undefined
    }
    return p - 1;
  }

  void MAKENULL() {
    size = 0;
  }

  int FIRST() {
    if (size == 0) {
      return size; // Return END(L)
    }
    return 0;
  }

  int END() {
    return size; // Return next of last position
  }

  void PRINTLIST() {
    for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int LOCATEInRange(int x, int s, int f) {
    for (int i = s; i < f; ++i) {
      if (arr[i] == x) {
        return i;
      }
    }
    return -1; // Not found
  }
};

int SUM(List L) {
  int sum = 0;
  for (int i = L.FIRST(); i < L.END(); i++) {
    sum += L.RETRIEVE(i);
  }
  return sum;
}

List Reverse(List L) {
  List rev;

  for (int i = L.FIRST(); i < L.END(); i++) {
    rev.INSERT(L.RETRIEVE(L.END() - i), i);
  }

  return rev;
}

struct Result {
  List H1, H2;
};

Result Split(List L) {
  Result R;
  int count = 0;
  for (int i = 0; i < L.END(); i++)
  {
    if (L.RETRIEVE(i) % 2) {
      R.H1.INSERT(L.RETRIEVE(i), count);
      count++;
    }
    if (!(L.RETRIEVE(i) % 2)) {
      R.H2.INSERT(L.RETRIEVE(i), count);
      count++;
    }
  }
  return R;
}

List insertXafterY(List L, int x, int y) {
  L.INSERT(x, L.NEXT(L.LOCATE(y)));
  return L;
}

List Concatenate(List L1, List L2) {
  List L3;

  int p1 = L1.FIRST();
  int p2 = L2.FIRST();
  int p3 = L3.FIRST();

  while (p1 != L1.END()) {
    L3.INSERT(L1.RETRIEVE(p1), p3);
    p1 = L1.NEXT(p1);
    p3 = L3.NEXT(p3);
  }
  while (p2 != L2.END()) {
    L3.INSERT(L2.RETRIEVE(p2), p3);
    p2 = L2.NEXT(p2);
    p3 = L3.NEXT(p3);
  }
  return L3;
}

List Purge(List L) {
  int p1 = L.FIRST(), p2 = L.FIRST();
  while (p1 != L.END())
  {
    while (p2 != L.END())
    {
      p2 = L.NEXT(p1);
      if (L.RETRIEVE(p1) == L.RETRIEVE(p2)) {
        L.DELETE(p2);
        p2 = L.NEXT(p2);
      }
    }
    p1 = L.NEXT(p1);
  }
  return L;
}

int main() {
  List L;
  L.INSERT(5, 0);
  L.INSERT(10, 1);
  L.INSERT(15, 2);
  L.PRINTLIST();

  cout << "Position of 10: " << L.LOCATE(10) << endl;
  cout << "Element at position 1: " << L.RETRIEVE(1) << endl;

  L.DELETE(1);
  L.PRINTLIST();

  cout << "Next position after 5: " << L.NEXT(0) << endl;
  cout << "Previous position before 15: " << L.PREVIOUS(2) << endl;

  L.MAKENULL();
  L.PRINTLIST();

  return 0;
}