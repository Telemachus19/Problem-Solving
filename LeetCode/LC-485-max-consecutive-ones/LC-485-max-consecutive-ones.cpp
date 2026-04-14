#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0, maxCount = 0;
    const int length = nums.size();
    for (int i = 0; i < length; i++) {
      if (nums[i] == 1)
        maxCount = (++count > maxCount) ? count : maxCount;
      else
        count = 0;
    }
    return maxCount;
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
  vector<int> num1 = {1, 1, 0, 1, 1, 1};
  vector<int> num2 = {1, 0, 1, 1, 0, 1};
  Solution s;
  cout << s.findMaxConsecutiveOnes(num1) << endl;
  cout << s.findMaxConsecutiveOnes(num2) << endl;
  return 0;
}
