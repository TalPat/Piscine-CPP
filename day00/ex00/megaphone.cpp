#include <iostream>
#include <string>

void ft_capitalize(char *string) {
  int i = 0;
  while (string[i]) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] = string[i] + ('A' - 'a');
    } 
    i++;
  }
}

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++)
    {
      ft_capitalize(argv[i]);
      std::cout << argv[i];
    }
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  }
  std::cout << '\n';
  return (0);
}