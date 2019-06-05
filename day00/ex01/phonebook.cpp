#include <iostream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

bool isNumber(std::string str) {
  for (size_t i = 0; i < str.length(); i++)
  {
    if(!isdigit(str[i])) {
      return (false);
    }
  }
  return (true);
}

int main(void) {
  Contact obj[8];
  int counter = 0;
  std::string indexIn;
  std::string input = "";

  while (input != "EXIT") {
    std::cout << "'ADD', 'SEARCH', or 'EXIT'" << "\n";
    std::getline(std::cin, input);
    if (input == "ADD"){
      if (counter > 7) {
        std::cout << "Phonebook full" << "\n";
      } else {
        obj[counter].addData();
        counter++;
      }
    } else if(input == "SEARCH") {
      for (int i = 0; i < counter; i++)
      {
        std::cout << obj[i].fourColumn(i) << "\n";
      }
      std::cout << "Give the index for more info, type an invalid input to return" << "\n";
      std::getline(std::cin, indexIn);
      if (indexIn != "" && isNumber(indexIn) && std::stoi(indexIn) < counter) {
        obj[std::stoi(indexIn)].displayInfo();
      } else {
        std::cout << "invalid input" << "\n";
      }
    } else if (input == "EXIT") {
      break;
    }
    input = "";
  }
  return (0);
}