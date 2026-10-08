
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int GOAT_ARRAY_SIZE = 15;

class Goat {
private:
  int age;
  string name;
  string color;

  string names[GOAT_ARRAY_SIZE] = {
    "Billy", "Nanny", "Daisy", "Rocky", "Luna",
    "Milo", "Clover", "Pepper", "Oreo", "Willow",
    "Sunny", "Hazel", "Buddy", "Maple", "Stormy"
  };

  string colors[GOAT_ARRAY_SIZE] = {
    "White", "Black", "Brown", "Gray", "Cream",
    "Gold", "Red", "Yellow", "Tan", "Silver",
    "Beige", "Mauve", "Orange", "Copper", "Chocolate"
  };

public:
  // default constructor
  Goat() {
    age = rand() % 20 + 1;
    name = names[rand() % GOAT_ARRAY_SIZE];
    color = colors[rand() % GOAT_ARRAY_SIZE];
  }

  // parameter constructor
  Goat(int a, string n, string c) {
    age = a;
    name = n;
    color = c;
  }

  int getAge() {
    return age;
  }

  string getName() {
    return name;
  }

  string getColor() {
    return color;
  }
};

class DoublyLinkedList {
private:
  struct Node {
    Goat data;
    Node* prev;
    Node* next;

    Node(Goat value, Node* p = nullptr, Node* n = nullptr) {
      data = value;
      prev = p;
      next = n;
    }
  };

  Node* head;
  Node* tail;

public:
  // constructor
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void push_back(Goat value) {
    Node* newNode = new Node(value);

    if (!tail)
      head = tail = newNode;
    else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  void push_front(Goat value) {
    Node* newNode = new Node(value);

    if (!head)
      head = tail = newNode;
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  // print forward
  void print() {
    Node* current = head;

    if (!current) {
      cout << "List is empty" << endl;
      return;
    }

    while (current) {
      cout << "    " << current->data.getName()
           << " (" << current->data.getColor()
           << ", " << current->data.getAge()
           << ")" << endl;

      current = current->next;
    }
  }

  // print backward
  void print_reverse() {
    Node* current = tail;

    if (!current) {
      cout << "List is empty" << endl;
      return;
    }

    while (current) {
      cout << "    " << current->data.getName()
           << " (" << current->data.getColor()
           << ", " << current->data.getAge()
           << ")" << endl;

      current = current->prev;
    }
  }

  // destructor
  ~DoublyLinkedList() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  DoublyLinkedList list;

  // testing with three goats
  Goat goat1(6, "Billy", "White");
  Goat goat2(10, "Daisy", "Brown");
  Goat goat3(4, "Rocky", "Black");

  list.push_back(goat1);
  list.push_back(goat2);
  list.push_front(goat3);

  cout << "Forward:" << endl;
  list.print();

  cout << endl << "Backward:" << endl;
  list.print_reverse();

  return 0;
}
