#include <iostream>
#include <string>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* strPtr = &str;
    std::string& strRef = str;

    // strRef = "asd";

    std::cout << *strPtr << std::endl;
    std::cout << strRef << std::endl;
    return (0);
}