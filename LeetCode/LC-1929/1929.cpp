#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < 2; i++) {
      for (int num : nums) {
        result.push_back(num);
      }
    }
    return result;
  }
};
void printArray(const int arr[], const int size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    cout << arr[i];
    if (i < size - 1)
      cout << ",";
  }
  cout << "]\n";
}
void printVector(const vector<int> &vec) {
  cout << "[";
  for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i];
    if (i < vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;

  int temp;
  vector<int> nums;
  for (int i = 0; i < t; i++) {
    cin >> temp;
    nums.push_back(temp);
  }
  Solution s;
  vector<int> res = s.getConcatenation(nums);
  // Print Input
  printVector(nums);
  printVector(res);
  return 0;
}
