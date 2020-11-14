/**
 * @defgroup   BANK bank
 *
 * @brief      This file implements bank.
 *
 * @todo       maybe add implementation for delete and save in file bank data;
 *
 * @author     Anhuk (nederb@gmail.com)
 * @date       2020
 */
#pragma once
#include <string>
#include <vector>
#include <ostream>
#include <initializer_list>

/// @brief Struct for person full name
struct person {
  std::string name;
  std::string surname;
  std::string patronymic;
  /// add age and passport id someday

  friend std::ostream& operator<<(std::ostream& os, const person& p);
};

/// @class Bank @file bank.h
/// @brief Bank manager. Store the data of accounts
class Bank {
  /// Types:
  std::vector<person> personList;
  std::vector<unsigned int> IDList;
  int size;

public:
  /// @brief CTOR. Initialize the size to zero
  Bank();

  /// @brief CTOR with list. Initialize the person with default ID.
  /// @param list - List of person
  Bank(const std::initializer_list<person> &list);

  /// @brief Add the account to bank
  /// @param p  Person data
  void addAccount(const person& p);

  /// @brief Print all accounts to the console
  void print() const;

  /// @brief Get the person with ID. If not the ID
  /// return the last person
  /// @param ID person ID
  /// @return person
  const person& operator[](const unsigned int ID);

  /// @brief Return the size of list.
  /// @return Size of list
  constexpr int length() const { return size; }
};
