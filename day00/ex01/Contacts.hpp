#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

class Contact {
  public:
    void addData();
    std::string fourColumn(int intIndex);
    void displayInfo();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getLogin();
    std::string getPostalAddress();
    std::string getEmailAddress();
    std::string getPhoneNumber();
    std::string getBirthdayDate();
    std::string getFavouriteMeal();
    std::string getUnderwearColor();
    std::string getDarkestSecret();
  private:
    std::string firstName, lastName, nickname, login, postalAddress, emailAddress, phoneNumber, birthdayDate, favoriteMeal, underwearColor, darkestSecret;
};

#endif