#include <climits>
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

long long maxSubarraySum(vector<int> &nums, int k) {
  long long size = nums.size();
  vector<long long> minArr(k, LLONG_MAX);
  minArr[k - 1] = 0;
  long long prefix_sum = 0, max_sum = LLONG_MIN;
  for (long long i = 0; i < size; i++) {
    prefix_sum += nums[i];
    int r = i % k;
    if (minArr[r] != LLONG_MAX) {
      long long ksum = prefix_sum - minArr[r];
      if (ksum > max_sum)
        max_sum = ksum;
    }
    if (prefix_sum < minArr[r])
      minArr[r] = prefix_sum;
  }
  return max_sum;
}

int main() {
  cout << "--- Running Tests ---" << endl;
  runTest("nums = [1, 2]", maxSubarraySum, 3, vector<int>{1, 2}, 1);
  runTest("nums = [-1, 9, 8, -1], k = 2", maxSubarraySum, 17,
          vector<int>{-1, 9, 8, -1}, 2);
  runTest("nums = [-5, 1, 2, -3, 4], k = 2", maxSubarraySum, 4,
          vector<int>{-5, 1, 2, -3, 4}, 2);
  runTest("nums = [-1, -2, -3, -4], k = 2", maxSubarraySum, -3,
          vector<int>{-1, -2, -3, -4}, 2);
  runTest("nums = [0, 0, 0, 0], k = 3", maxSubarraySum, 0,
          vector<int>{0, 0, 0, 0}, 3);
  runTest("nums = [5, -10, 5], k = 2", maxSubarraySum, -5,
          vector<int>{5, -10, 5}, 2);
  runTest("nums = [-10, 10, -2, 20, -5], k = 1", maxSubarraySum, 28,
          vector<int>{-10, 10, -2, 20, -5}, 1);
  runTest("nums = [1000000000, 1000000000], k = 1", maxSubarraySum, 2000000000,
          vector<int>{1000000000, 1000000000}, 1);
  // runTest("nums = [1, 2]", maxSubarraySum, 3, vector<int>{1, 2}, 1);

  // int k = 4;
  // vector<int> nums{-1, -2, -3, -4, -5};
  // long long size = nums.size();
  // long long maxSum = INT_MIN;
  // long long sum = 0;
  // // Outer Loop
  // while (k <= size) {
  //   for (int i = 0; i <= size - k; i++) {
  //     for (int j = i; j < i + k; j++) {
  //       cout << "j: " << j << endl;
  //       sum += nums[j];
  //     }
  //     cout << "Out of inner loop" << endl;
  //     maxSum = (sum > maxSum) ? sum : maxSum;
  //     sum = 0;
  //   }
  //   k += k;
  // }
  // cout << maxSum << endl;
  return 0;
}
