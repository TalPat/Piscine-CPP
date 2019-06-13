#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
  Base* myBase;
  int ranno = rand() % 3;
  if (ranno == 0) {
    myBase = new A;
  } else if (ranno == 1) {
    myBase = new B;
  } else if (ranno == 2) {
    myBase = new C;
  } else {
    myBase = NULL;
  }
  return (myBase);
}

void identify_from_pointer( Base * p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  }
  if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  }
  if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  }
}

void identify_from_reference( Base & p ) {
  if (dynamic_cast<A*>(&p)) {
    std::cout << "A" << std::endl;
  }
  if (dynamic_cast<B*>(&p)) {
    std::cout << "B" << std::endl;
  }
  if (dynamic_cast<C*>(&p)) {
    std::cout << "C" << std::endl;
  }
}

int main(void) {
  Base* myBase = generate();
  identify_from_pointer(myBase);
  identify_from_reference(*myBase);
  return (0);
}