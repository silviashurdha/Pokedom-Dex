#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  LinkedList<Pokemon> ll; // Create linked list a that takes in pokemon objects

  char input;
  std::string name = "";
  std::string type = "";
  int level = 0;

  cout << "Welcome to your Pokedex! Here are the commands available on this "
          "device\n";
  cout << "h: Prints out help list.\n";
  cout << "a: Add new Pokemon to your Pokedex with a name, type and "
          "level.\n";
  cout << "r: Choose a Pokemon to release back into the wild\n";
  cout << "p: Print out the list of all Pokemon in your Pokedex.\n";
  cout << "s: Search for a Pokemon by name and print their information "
          "from your dex.\n";
  cout << "e: Exits the program.\n";

  do {

    cout << "\nEnter your choice:\n";
    cin >> input;
    switch (input) {
    case 'a': {
      cout << "Add your pokemon, enter the name, type and level\n";
      cout << "Name: ";
      cin >> name;
      cout << "Type: ";
      cin >> type;
      bool valid = false;
      do {
        cout << "Level: ";
        cin >> level;
        if (cin.good()) {
          valid = true;
        } else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Please enter an integer for the level.\n";
        }
      } while (!valid);

      Pokemon newPokemon(name, type, level);
      ll.addFront(newPokemon);
      break;
    }
    case 's': {
      cout << "Enter the name of which Pokemon you'd like to find: ";
      cin >> name;
      ll.search(name);
      break;
    }
    case 'r': {
      cout << "Enter the name of which pokemon you'd like to release: ";
      cin >> name;
      ll.deleteNode(name);
      break;
    }
    case 'p': {
      cout << "Printing the Pokedex:\n";
      ll.printList();
      break;
    }
    case 'e': {
      cout << "The pokedex is now closing!\n";
      break;
    }
    case 'h': {
      cout << "\nHelp:\n";
      cout << "h: Prints out help list.\n";
      cout << "a: Add new Pokemon to your Pokedex with a name, type and "
              "level.\n";
      cout << "r: Choose a Pokemon to release back into the wild\n";
      cout << "p: Print out the list of all Pokemon in your Pokedex.\n";
      cout << "s: Search for a Pokemon by name and print their information "
              "from your dex.\n";
      cout << "e: Exits the program.";
      break;
    }
    default: {
      cout << "Not a valid input, try again\n";
      break;
    }
    }
  } while (input != 'e');

  return 0;
}