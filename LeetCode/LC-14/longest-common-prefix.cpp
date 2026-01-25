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

string longestCommonPrefix(vector<string> &strs) {
  bool isEmpty = strs.empty();
  string pre = (isEmpty) ? "" : strs[0];
  int size = strs.size();
  for (int i = 1; i < size; i++) {
    while (strs[i].find(pre) != 0 && !isEmpty) {
      pre = pre.substr(0, pre.length() - 1);
      isEmpty = pre.empty();
    }
  }
  return pre;
}

int main() {
  cout << "--- Running Tests ---" << endl;
  runTest("flower,flow,flight", longestCommonPrefix, "fl",
          vector<string>{"flower", "flow", "flight"});
  vector<string> s = {};
  cout << longestCommonPrefix(s);
  return 0;
}
