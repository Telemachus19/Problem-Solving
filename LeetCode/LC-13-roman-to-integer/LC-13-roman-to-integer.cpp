#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

template <typename T> string toString(const T &t) {
  stringstream ss;
  ss << boolalpha << t;
  return ss.str();
}

template <typename Func, typename Exp, typename... Args>
void runTest(string name, Func func, Exp expected, Args... args) {
  auto result = func(args...);
  bool pass = (result == expected);
  cout << (pass ? "\033[32m[PASS] \033[0m" : "\033[31m[FAIL] \033[0m") << name
       << endl;
  if (!pass) {
    cout << "   Expected: " << toString(expected) << endl;
    cout << "   Got:      " << toString(result) << endl;
  }
}

int romanToInt(string s) {
  int restult = 0, current_value, previous_value = 0, length = s.length() - 1;
  int map[128];
  map['I'] = 1;
  map['V'] = 5;
  map['X'] = 10;
  map['L'] = 50;
  map['C'] = 100;
  map['D'] = 500;
  map['M'] = 1000;
  for (int i = length; i >= 0; i--) {
    current_value = map[s[i]];
    if (current_value < previous_value) {
      restult -= current_value;
    } else {
      restult += current_value;
    }
    previous_value = current_value;
  }
  return restult;
}
int main() {
  cout << "--- Running Tests ---" << endl;
  runTest("III", romanToInt, 3, "III");
  runTest("LVIII", romanToInt, 58, "LVIII");
  runTest("MCMXCIV", romanToInt, 1994, "MCMXCIV");
  return 0;
}
