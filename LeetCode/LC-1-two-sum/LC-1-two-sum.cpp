#include <array>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

template <typename T> string toString(const T& t) {
    stringstream stream;
    stream << boolalpha << t;
    return stream.str();
}

template <typename Func, typename Exp, typename... Args>
void runTest(string name, Func func, Exp expected, Args... args) {
    auto result = func(args...);
    bool pass = (result == expected);
    cout << (pass ? "\033[32m[PASS] \033[0m" : "\033[31m[FAIL] \033[0m") << name << endl;
    if (!pass) {
        cout << "   Expected: " << toString(expected) << endl;
        cout << "   Got:      " << toString(result) << endl;
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    // first pass: O(n^2) time, O(1) space
    // for (size_t i = 0; i < nums.size(); ++i) {
    //     for (size_t j = i + 1; j < nums.size(); ++j) {
    //         if (nums[i] + nums[j] == target) {
    //             return {(int)i, (int)j};
    //         }
    //     }
    // }
    // return {};
    bool found = false;
    unordered_map<int, int> seen;
    vector<int> result;
    for (int i = 0; i < nums.size() && !found; ++i) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            result = {seen[complement], i};
            found = true;
        }
        seen[nums[i]] = i;
    }
    return result;
}

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", twoSum, expected, arg1);
    vector<int> example1{2, 7, 11, 15};
    vector<int> example2{3, 2, 4};
    vector<int> example3{3, 3};
    array<int, 3> targets{9, 6, 6};
    runTest("nums = [2,7,11,15], target = 9", twoSum, vector<int>{0, 1}, example1, targets[0]);
    runTest("nums = [3,2,4], target = 6", twoSum, vector<int>{1, 2}, example2, targets[1]);
    runTest("nums = [3,3], target = 6", twoSum, vector<int>{0, 1}, example3, targets[2]);
    return 0;
}
