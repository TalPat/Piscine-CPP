#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

class Contact {
  public:
    void addData();
    std::string fourColumn(int intIndex);
    void displayInfo();
  private:
    std::string firstName, lastName, nickname, login, postalAddress, emailAddress, phoneNumber, birthdayDate, favoriteMeal, underwearColor, darkestSecret;
};

#endif