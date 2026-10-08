
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int GOAT_ARRAY_SIZE = 15;
const int MIN_GOATS = 5;
const int MAX_GOATS = 20;

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
  srand(time(0));

  DoublyLinkedList list;

  // generate a random number of goats
  int size = rand() % (MAX_GOATS - MIN_GOATS + 1) + MIN_GOATS;

  // add random goats to the list
  for (int i = 0; i < size; i++) {
    Goat newGoat;
    list.push_back(newGoat);
  }

  cout << "Forward:" << endl;
  list.print();

  cout << endl << "Backward:" << endl;
  list.print_reverse();

  // test an empty list
  DoublyLinkedList emptyList;

  cout << endl << "Empty list forward:" << endl;
  emptyList.print();

  cout << endl << "Empty list backward:" << endl;
  emptyList.print_reverse();

  return 0;
}
