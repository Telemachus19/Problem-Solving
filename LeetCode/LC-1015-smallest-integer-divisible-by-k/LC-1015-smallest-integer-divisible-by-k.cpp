#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
  os << "[";
  for (size_t i = 0; i < v.size(); ++i)
  {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

template <typename T>
string toString(const T &t)
{
  stringstream ss;
  ss << boolalpha << t;
  return ss.str();
}

template <typename Func, typename Exp, typename... Args>
void runTest(string name, Func func, Exp expected, Args... args)
{
  auto result = func(args...);
  bool pass = (result == expected);
  cout << (pass ? "\033[32m[PASS] \033[0m" : "\033[31m[FAIL] \033[0m") << name
       << endl;
  if (!pass)
  {
    cout << "   Expected: " << toString(expected) << endl;
    cout << "   Got:      " << toString(result) << endl;
  }
}

int smallestRepunitDivByK(int k)
{
  int len = 0, n = 1;
  bool divisible = false;
  bool exit = (k % 2 == 0) || (k % 5 == 0);
  while (!divisible && !exit)
  {
    divisible = (n % k == 0);
    len++;
    n = ((n * 10) + 1) % k;
  }
  return (divisible) ? len : -1;
}

int main()
{
  cout << "--- Running Tests ---" << endl;
  // runTest("k = 1", smallestRepunitDivByK, 1, 1);
  // runTest("k = 2", smallestRepunitDivByK, -1, 2);
  runTest("k = 3", smallestRepunitDivByK, 3, 3);
  runTest("k = 5", smallestRepunitDivByK, -1, 5);
  runTest("k = 7", smallestRepunitDivByK, 6, 7);
  runTest("k = 11", smallestRepunitDivByK, 2, 11);
  runTest("k = 15", smallestRepunitDivByK, -1, 15);
  runTest("k = 20", smallestRepunitDivByK, -1, 20);
  runTest("k = 25", smallestRepunitDivByK, -1, 25);
  runTest("k = 989", smallestRepunitDivByK, 462, 989);

  return 0;
}
