#include "bank.h"
#include <iostream>
#include <stdexcept>

std::ostream &operator<<(std::ostream &os, const person &p) {
  os << p.name << " " << p.surname << " " << p.patronymic;
  return os;
}

Bank::Bank() { size = 0; }

Bank::Bank(const std::initializer_list<person> &list) {
  for (const auto &p : list) {
    addAccount(p);
  }
}

void Bank::addAccount(const person &p) {
  personList.push_back(p);
  size++;
  IDList.push_back(size * sizeof p);
}

void Bank::print() const {
  if (size == 0) {
    std::cout << "List is empty. " << std::endl;
    return;
  }
  std::cout << "ID\t\t\t\tPerson" << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << IDList[i] << "\t\t\t" << personList[i] << std::endl;
  }
}

const person &Bank::operator[](const unsigned int ID) {
  if (size == 0) {
    throw std::logic_error("List is empty. ");
  }
  for (int i = 0; i < size; i++) {
    if (ID == IDList[i])
      return personList[i];
  }
  throw std::logic_error("There is not person with this ID.");
}
