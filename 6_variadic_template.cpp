#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T> std::string to_string_impl(const T &val) {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::vector<std::string> to_string() { return {}; }

// variadic template calling itselft recursively
template <typename Param, typename... Params>
std::vector<std::string> to_string(const Param &p, const Params &...params) {
  std::vector<std::string> vecstr;
  vecstr.push_back(to_string_impl(p));
  const auto remainingParams = to_string(params...);
  vecstr.insert(vecstr.end(), remainingParams.begin(), remainingParams.end());
  return vecstr;
}

// It reduces compile time and generated code is much smaller in size. It is
// using vector initializer list and template inflating inside it
template <typename... Params>
std::vector<std::string> to_string_modern(const Params &...params) {
  return {to_string_impl(params)...};
}

int main() {
  std::cout << to_string_impl(5) << std::endl;
  auto vecstr = to_string_modern2("hello", 6, 6.6f, 6.7);
  for (const auto &v : vecstr) {
    std::cout << v << std::endl;
  }
  return 0;
}
