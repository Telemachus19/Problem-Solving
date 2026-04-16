#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
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

int removeElement(vector<int>& nums, int val) {
    int remaining_element_count = 0;
    int left = 0;
    int right = static_cast<int>(nums.size() - 1);
    while (left <= right) {
        if (nums[left] != val) {
            remaining_element_count++;
            left++;
        } else if (nums[right] == val) {
            right--;
        } else if (nums[left] == val && nums[right] != val) {
            swap(nums[left], nums[right]);
            left++;
            right--;
            remaining_element_count++;
        }
    }

    // cout << nums << endl;
    // cout << remaining_element_count << endl;
    return remaining_element_count;
}

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", solve, expected, arg1);
    vector<int> nums = {3, 2, 2, 3};
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    removeElement(nums, 3);
    removeElement(nums2, 2);
    return 0;
}
