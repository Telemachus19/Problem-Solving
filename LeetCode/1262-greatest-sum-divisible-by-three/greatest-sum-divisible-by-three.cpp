#include <cstdint>
#include <cstring>
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
struct testCase {
  vector<int> vec;
  int expected;
};

int maxSumDivThree(vector<int> &nums) {
  int smallest_rem = INT32_MAX;
  long long sum = 0;
  for (int n : nums) {
    if (n % 3 == 2)
      smallest_rem = (n < smallest_rem) ? n : smallest_rem;
    sum += n;
    cout << sum << endl;
  }
  return sum - smallest_rem;
}

int main() {
  cout << "--- Running Tests ---" << endl;
  // runTest("Test Name", funcName, expectedVal, input1, input2...);
  vector<testCase> tests = {
      {{3, 6, 9}, 18},       {{1, 2, 3, 4, 4}, 12}, {{3, 6, 5, 1, 8}, 18},
      {{2, 6, 2, 2, 7}, 15}, {{2, 2, 2, 2}, 6},     {{5, 5, 5, 2}, 15},
      {{1, 100}, 0},         {{0, 0, 0}, 0},        {{}, 0}};
  int test_size = tests.size();
  string test_str = "TEST ";
  for (int i = 0; i < test_size; i++) {

    runTest(test_str + to_string(i), maxSumDivThree, tests[i].expected,
            tests[i].vec);
  }

  return 0;
}
