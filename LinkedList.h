#ifndef LINKLIST_H
#define LINKLIST_H

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Pokemon class to hold the data about pokemons
class Pokemon {
private:
  string name;
  string type;
  int level;

public:
  // Defualt pokemon constructor
  Pokemon() {
    name = " ";
    type = " ";
    level = 0;
  }

  // Pokemon constructor to add data to values
  Pokemon(string n, string t, int l) {
    name = n;
    type = t;
    level = l;
  }

  // Print pokemon data
  void printPokemon() {
    // cout << name << " " << type << " " << level << "\n";
    cout << left << setw(13) << name << setw(10) << type << setw(5) << level
         << endl;
  }

  // Getter for name
  string getName() { return name; }

  // getter for type
  string getType() { return type; }

  // getter for level
  int getLevel() { return level; }
};

// Declare linked list for node class
template <typename E> class LinkedList;

// Declare node class with the typename
template <typename E> class Node {
private:
  E elem;
  Node<E> *next;

public:
  Node(){};
  Node(E p, Node<E> *n) {
    elem = p;
    next = n;
  }

  friend class LinkedList<E>;
};

template <typename E> class LinkedList {
private:
  Node<E> *head;
  int size;

public:
  LinkedList() { 
    head = NULL;
    size = 0;
    }

  ~LinkedList() {
    while (!empty())
      removeFront();
  }

  bool empty() const { return head == NULL; }
  const E front() const { return head->elem; }

  void addFront(const E e) {
    Node<E> *newNode = new Node<E>;
    newNode->elem = e;
    newNode->next = head;
    head = newNode;
    size++;
  }

  void removeFront() {
    Node<E> *old = head;
    head = old->next;
    delete old;
  }

  void printList() {
    Node<E> *curr = head;
    cout << "Your Pokedex has " << size << " pokemon in it!" << "\n\n";
    cout << left << setw(13) << "Name" << setw(10) << "Type" << setw(5)
         << "Level" << endl;
    cout << "----------------------------" << endl;
    while (curr != NULL) {
      curr->elem.printPokemon();
      curr = curr->next;
    }
  }

  void deleteNode(string n) {

    Node<E> *curr = head;
    Node<E> *prev = NULL;

    while (curr != NULL) {
      if (curr->elem.getName() == n) {
        if (curr == head) {
          head = curr->next;
          delete curr;
          cout << "Selected Pokemon was released!\n";
          size--;
          return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Selected Pokemon was released!\n";
        size--;
        return;
      }
      prev = curr;
      curr = curr->next;
    }

    cout << "This Pokemon is not in your Pokedex\n";
  }
  void search(std::string n) {
    Node<E> *curr = head;

    while (curr != NULL) {
      if (curr->elem.getName() == n) {
        cout << "Here is the Pokemon in the dex matching the name:\n";
        cout << left << setw(13) << "Name" << setw(10) << "Type" << setw(5)
             << "Level" << endl;
        cout << "----------------------------" << endl;
        curr->elem.printPokemon();
        return;
      }
      curr = curr->next;
    }
    cout << "This Pokemon has not been added to your Pokedex\n";
  }
};

#endif