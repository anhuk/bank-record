#include <iostream>
#include "bank.h"

int main() {
  Bank f;
  int n;

  std::cout << "Enter the number of person: ";
  std::cin >> n;
  while (n--) {
    person t;
    std::cout << std::endl << "Enter the full name of person #" << n << ": ";
    std::cin >> t.name >> t.surname >> t.patronymic;
    f.addAccount(t);
  }

  f.print();
  std::cout << "Enter the ID of person: ";
  std::cin >> n;
  std::cout << f[n] << std::endl;

  std::cout << "Pres the Enter to continue.";
  std::cin >> n;
  return 0;
}
