#include <iostream>
#include <string>
#include <cstdlib>


struct Data
{
  std::string charArr1;
  int datInt;
  std::string charArr2;
};

void* serialize(void) {
  Data* myData = new Data;
  for (size_t i = 0; i < 8; i++)
  {
    myData->charArr1 += rand()%36 > 9 ? rand()%26 + 'a' : rand()%10 + '0';
    myData->charArr2 += rand()%36 > 9 ? rand()%26 + 'a' : rand()%10 + '0';
  }
  myData->datInt = rand();
  return (myData);
}

Data *deserialize(void* raw) {
  return (reinterpret_cast<Data*>(raw));
}

int main(void) {
  void* ptr = serialize();
  Data* myData = deserialize(ptr);
  std::cout << "strarr1: " << myData->charArr1 << std:: endl;
  std::cout << "integer: " << myData->datInt << std:: endl;
  std::cout << "strarr2: " << myData->charArr2 << std:: endl;
}

