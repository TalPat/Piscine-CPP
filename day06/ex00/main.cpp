#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>

char ft_tochar(char* str) {
  float val = atof(str); 
  if (val >= 32 && val <= 127) {
    return (static_cast<char>(val));
  } else {
    throw "impossible";
  }
}

int ft_toint(char* str) {
  float val = atof(str);
  if (val <= std::numeric_limits<int>::max() && val >= std::numeric_limits<int>::min()) {
    return (static_cast<int>(val));
  } else {
    throw "impossible";
  }
}

float ft_tofloat(char* str) {
  float val = atof(str); 
  return (static_cast<float>(val));
}

double ft_todouble(char* str) {
  float val = atof(str); 
  return (static_cast<double>(val));
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "invalid input" << std:: endl;
  } else {
    try
    {
      std::cout << "char: " << ft_tochar(argv[1]) << std::endl;
    }
    catch(const char * e)
    {
      std::cout << e << std::endl;
    }
    try
    {
      std::cout << "int: " << ft_toint(argv[1]) << std::endl;
    }
    catch(const char* e)
    {
      std::cout << e << std::endl;
    }
    std::cout << "float: " << ft_tofloat(argv[1]) << "f" << std::endl;
    std::cout << "double: " << ft_todouble(argv[1]) << std::endl;
  }
  return (0);
}