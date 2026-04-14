#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
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

bool containsDuplicate(vector<int>& nums) {
    // first pass: O(n) time, O(n) space
    unordered_set<int> seen;
    bool containsDup = false;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            containsDup = true;
            break;
        }
        seen.insert(num);
    }
    return containsDup;
}

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", containsDuplicate, expected, arg1);
    vector<int> nums1{1, 2, 3, 1};
    vector<int> nums2{1, 2, 3, 4};
    vector<int> nums3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    array<bool, 3> expected{true, false, true};
    runTest("nums1: {1,2,3,1}, containsDuplicate = true", containsDuplicate, expected[0], nums1);
    runTest("nums2: {1,2,3,4}, containsDuplicate = false", containsDuplicate, expected[1], nums2);
    runTest("nums3: {1,1,1,3,3,4,3,2,4,2}, containsDuplicate = true", containsDuplicate,
            expected[2], nums3);
    return 0;
}
