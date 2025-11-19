#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> res;
    res.reserve(2 * n);
    for (int i = 0; i < n; i++) {
      res.push_back(nums[i]);
      res.push_back(nums[i + n]);
    }
    return res;
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
  int n = 3;
  vector<int> nums = {2, 5, 1, 3, 4, 7};
  vector<int> res;
  for (int i = 0, j = n; i < n; i++, j++) {
    res.push_back(nums[i]);
    res.push_back(nums[j]);
  }
  printVector(res);
  return 0;
}
