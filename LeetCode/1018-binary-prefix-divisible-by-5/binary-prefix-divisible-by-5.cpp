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

vector<bool> prefixesDivBy5(vector<int> &nums) {
  vector<bool> res;
  unsigned long long n = nums[0], size = nums.size();
  res.push_back(n % 5 == 0);
  for (int i = 1; i < size; i++) {
    n = ((n << 1) | nums[i]) % 5;
    res.push_back(n == 0);
  }
  return res;
}
int main() {
  cout << "--- Running Tests ---" << endl;
  runTest("Example 1 [0,1,1]", prefixesDivBy5, vector<bool>{true, false, false},
          vector<int>{0, 1, 1});
  runTest("All Ones [1,1,1]", prefixesDivBy5, vector<bool>{false, false, false},
          vector<int>{1, 1, 1});
  runTest("Pattern [1,0,1,0,0]", prefixesDivBy5,
          vector<bool>{false, false, true, true, true},
          vector<int>{1, 0, 1, 0, 0});
  runTest("All Zeros", prefixesDivBy5, vector<bool>{true, true, true},
          vector<int>{0, 0, 0});
  runTest("Ends with 25", prefixesDivBy5,
          vector<bool>{false, false, false, false, true},
          vector<int>{1, 1, 0, 0, 1});
  runTest("Single 0", prefixesDivBy5, vector<bool>{true}, vector<int>{0});
  runTest("Single 1", prefixesDivBy5, vector<bool>{false}, vector<int>{1});
  runTest("Quad Ones [1,1,1,1]", prefixesDivBy5,
          vector<bool>{false, false, false, true}, vector<int>{1, 1, 1, 1});
  runTest("Leading Zeros [0,0,1,0,1]", prefixesDivBy5,
          vector<bool>{true, true, false, false, true},
          vector<int>{0, 0, 1, 0, 1});
  runTest("Persistent Divisibility", prefixesDivBy5,
          vector<bool>{false, false, true, true, true, true, true},
          vector<int>{1, 0, 1, 0, 0, 0, 0});
  runTest("Break Streak [1,0,1,0,0,1]", prefixesDivBy5,
          vector<bool>{false, false, true, true, true, false},
          vector<int>{1, 0, 1, 0, 0, 1});
  runTest("I dunno", prefixesDivBy5,
          vector<bool>{false, false, false, false, false, false, false, false,
                       false, false, false, false, false, false, false, false,
                       false, false, false, false, false, false, false, false,
                       false, false, false, false, false, false, false, true,
                       false, false, true,  true,  true,  true,  false},
          vector<int>{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                      1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1});
  runTest("I dunno 2", prefixesDivBy5,
          vector<bool>{false, false, true,  false, false, false, false, false,
                       false, false, true,  true,  true,  true,  true,  true,
                       false, false, false, false, false, false, false, false,
                       false, false, false, false, false, false, false, false,
                       false, false, false, false, false, false, false, false,
                       false, false, false, true,  false, false, false, true,
                       false, false, true,  false, false, true,  true,  true,
                       true,  true,  true,  true,  false, false, true,  false,
                       false, false, false, true,  true},
          vector<int>{1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                      0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
                      1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
                      0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0});

  return 0;
}
