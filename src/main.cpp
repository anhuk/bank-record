#include "bank.h"
#include "menu.h"

int main() {
  Bank f;
  bool running{true};
  const ConsoleMenu menu{"What should do?\n",
                         "Invalid operation; ",
                         "> ",
                         {{"exit", [&running] { running = false; }},
                          {"add",
                           [&f] {
                             person p;
                             std::cout << "Enter the full name of person #"
                                       << f.length() + 1 << ": ";
                             std::cin >> p.name >> p.surname >> p.patronymic;
                             f.addAccount(p);
                           }},
                          {"print", [&f] { f.print(); }},
                          {"id", [&f] {
                             int ID;
                             std::cout << "Enter the ID of person: ";
                             std::cin >> ID;
                             std::cout << f[ID] << std::endl;
                             std::getchar();
                           }}}};

  while (running) {
    menu();
  }

  return 0;
}
