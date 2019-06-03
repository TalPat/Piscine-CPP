#include <iostream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

// class Contact {
//   public:
//     Contact() {
//     }
//     void addData() {
//       std::cout << "first name" << "\n";
//       std::cin >> firstName;
//       std::cout << "last name" << "\n";
//       std::cin >> lastName;
//       std::cout << "nickname" << "\n";
//       std::cin >> nickname;
//       std::cout << "login" << "\n";
//       std::cin >> login;
//       std::cout << "postal address" << "\n";
//       std::cin >> postalAddress;
//       std::cout << "email address" << "\n";
//       std::cin >> emailAddress;
//       std::cout << "phone number" << "\n";
//       std::cin >> phoneNumber;
//       std::cout << "birthday date" << "\n";
//       std::cin >> birthdayDate;
//       std::cout << "favorite meal" << "\n";
//       std::cin >> favoriteMeal;
//       std::cout << "underwear color" << "\n";
//       std::cin >> underwearColor;
//       std::cout << "darkest secret" << "\n";
//       std::cin >> darkestSecret;
//     }

//     std::string fourColumn(int intIndex) {
//       std::string index = std::to_string(intIndex);
//       std::string display;
//       display = "         " + index + "|";
//       if (firstName.length() > 10) {
//         display = display + firstName.substr(0, 9) + ".|";
//       } else {
//         for (int i = firstName.length(); i < 10; i++)
//         {
//           display = display + " ";
//         }
//         display = display + firstName + "|";
//       }
//       if (lastName.length() > 10) {
//         display = display + lastName.substr(0, 9) + ".|";
//       } else {
//         for (int i = lastName.length(); i < 10; i++)
//         {
//           display = display + " ";
//         }
//         display = display + lastName + "|";
//       }
//       if (nickname.length() > 10) {
//         display = display + nickname.substr(0, 9) + ".|";
//       } else {
//         for (int i = nickname.length(); i < 10; i++)
//         {
//           display = display + " ";
//         }
//         display = display + nickname + "|";
//       }
//       return (display);
//     }

//     void displayInfo() {
//       std::cout << firstName << "\n";
//       std::cout << lastName << "\n";
//       std::cout << nickname << "\n";
//       std::cout << login << "\n";
//       std::cout << postalAddress << "\n";
//       std::cout << emailAddress << "\n";
//       std::cout << phoneNumber << "\n";
//       std::cout << birthdayDate << "\n";
//       std::cout << favoriteMeal << "\n";
//       std::cout << underwearColor << "\n";
//       std::cout << darkestSecret << "\n";
//     }
//   private:
//     std::string firstName, lastName, nickname, login, postalAddress, emailAddress, phoneNumber, birthdayDate, favoriteMeal, underwearColor, darkestSecret;
// };

bool isNumber(std::string str) {
  for (int i = 0; i < str.length(); i++)
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
    std::cin >> input;
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
      std::cin >> indexIn;
      if (isNumber(indexIn)) {
        obj[std::stoi(indexIn)].displayInfo();
      } else {
        std::cout << "invalid input" << "\n";
      }
    }
    input = "";
  }
}