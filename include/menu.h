#pragma once
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

class ConsoleMenu {
public:
  ConsoleMenu(const std::string &message,
              const std::string &invalidChoiceMessage,
              const std::string &prompt,
              const std::unordered_map<std::string, std::function<void()>>
                  &commandsByC,
              std::istream &in = std::cin, std::ostream &out = std::cout);

  void operator()() const;

private:
  std::string invalidChoiceMessage_;
  std::string prompt_;
  std::unordered_map<std::string, std::function<void()>> commandsByChoice_;
  std::istream &in;
  std::ostream &out;
};
