#include "Contacts.hpp"
#include <iostream>
#include <string>

void Contact::addData() {
  std::cout << "first name" << "\n";
  std::getline(std::cin, firstName, '\n');
  std::cout << "last name" << "\n";
  std::getline(std::cin, lastName);
  std::cout << "nickname" << "\n";
  std::getline(std::cin, nickname);
  std::cout << "login" << "\n";
  std::getline(std::cin, login);
  std::cout << "postal address" << "\n";
  std::getline(std::cin, postalAddress);
  std::cout << "email address" << "\n";
  std::getline(std::cin, emailAddress);
  std::cout << "phone number" << "\n";
  std::getline(std::cin, phoneNumber);
  std::cout << "birthday date" << "\n";
  std::getline(std::cin, birthdayDate);
  std::cout << "favorite meal" << "\n";
  std::getline(std::cin, favoriteMeal);
  std::cout << "underwear color" << "\n";
  std::getline(std::cin, underwearColor);
  std::cout << "darkest secret" << "\n";
  std::getline(std::cin, darkestSecret);
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


std::string Contact::getFirstName(){
  return(this->firstName);
}
std::string Contact::getLastName(){
  return(this->lastName);
}
std::string Contact::getNickName(){
  return(this->nickname);
}
std::string Contact::getLogin(){
  return(this->login);
}
std::string Contact::getPostalAddress(){
  return(this->postalAddress);
}
std::string Contact::getEmailAddress(){
  return(this->emailAddress);
}
std::string Contact::getPhoneNumber(){
  return(this->phoneNumber);
}
std::string Contact::getBirthdayDate(){
  return(this->birthdayDate);
}
std::string Contact::getFavouriteMeal(){
  return(this->favoriteMeal);
}
std::string Contact::getUnderwearColor(){
  return(this->underwearColor);
}
std::string Contact::getDarkestSecret(){
  return(this->darkestSecret);
}
