#include "Contacts.hpp"
#include <iostream>
#include <string>

void Contact::addData() {
  std::cout << "first name" << "\n";
  std::cin >> firstName;
  std::cout << "last name" << "\n";
  std::cin >> lastName;
  std::cout << "nickname" << "\n";
  std::cin >> nickname;
  std::cout << "login" << "\n";
  std::cin >> login;
  std::cout << "postal address" << "\n";
  std::cin >> postalAddress;
  std::cout << "email address" << "\n";
  std::cin >> emailAddress;
  std::cout << "phone number" << "\n";
  std::cin >> phoneNumber;
  std::cout << "birthday date" << "\n";
  std::cin >> birthdayDate;
  std::cout << "favorite meal" << "\n";
  std::cin >> favoriteMeal;
  std::cout << "underwear color" << "\n";
  std::cin >> underwearColor;
  std::cout << "darkest secret" << "\n";
  std::cin >> darkestSecret;
}

std::string Contact::fourColumn(int intIndex) {
  std::string index = std::to_string(intIndex);
  std::string display;
  display = "         " + index + "|";
  if (firstName.length() > 10) {
    display = display + firstName.substr(0, 9) + ".|";
  } else {
    for (int i = firstName.length(); i < 10; i++)
    {
      display = display + " ";
    }
    display = display + firstName + "|";
  }
  if (lastName.length() > 10) {
    display = display + lastName.substr(0, 9) + ".|";
  } else {
    for (int i = lastName.length(); i < 10; i++)
    {
      display = display + " ";
    }
    display = display + lastName + "|";
  }
  if (nickname.length() > 10) {
    display = display + nickname.substr(0, 9) + ".|";
  } else {
    for (int i = nickname.length(); i < 10; i++)
    {
      display = display + " ";
    }
    display = display + nickname + "|";
  }
  return (display);
}

void Contact::displayInfo() {
  std::cout << firstName << "\n";
  std::cout << lastName << "\n";
  std::cout << nickname << "\n";
  std::cout << login << "\n";
  std::cout << postalAddress << "\n";
  std::cout << emailAddress << "\n";
  std::cout << phoneNumber << "\n";
  std::cout << birthdayDate << "\n";
  std::cout << favoriteMeal << "\n";
  std::cout << underwearColor << "\n";
  std::cout << darkestSecret << "\n";
}
