#include "menu.h"
#include <sstream>

ConsoleMenu::ConsoleMenu(
    const std::string &message,
    const std::string &invalidChoiceMessage,
    const std::string &prompt,
    const std::unordered_map<std::string, std::function<void()>>
        &commandsByC,
    std::istream &in, std::ostream &out)
    : invalidChoiceMessage_{invalidChoiceMessage},
      commandsByChoice_{commandsByC}, in{in}, out{out} {
  std::stringstream ss;
  ss << message;
  for (const auto &commandByChoice : commandsByChoice_) {
    ss << '[' << commandByChoice.first << ']' << '\n';
  }
  ss << prompt;
  prompt_ = ss.str();
}

void ConsoleMenu::operator()() const {
  std::system("clear");
  std::string userChoice;
  const auto bad{commandsByChoice_.cend()};
  auto result{bad};
  out << '\n';
  while ((out << prompt_) && (!(std::getline(in, userChoice)))
         || ((result = commandsByChoice_.find(userChoice)) == bad)) {
    out << '\n' << invalidChoiceMessage_;
         }
  result->second();
  /// Someday try to improve this code
  out << "\n" << "Enter the something to continue...";
  std::getchar();
}
