#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>

using namespace std;

// ---
// LeetCode Data Structures & Helpers
// ---
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Pretty Printer for Vectors
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

// Helper for string conversion in tests
template <typename T>
string toString(const T &t)
{
    stringstream ss;
    ss << boolalpha << t;
    return ss.str();
}

// Helper to create lists: makeList({1, 2, 3})
ListNode *makeList(const vector<int> &v)
{
    ListNode dummy(0);
    ListNode *curr = &dummy;
    for (int x : v)
    {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        string fizz = "Fizz";
        string buzz = "Buzz";
        string fizzbuzz = "FizzBuzz";

        vector<string> result;
        result.resize(n);

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
            {
                result.at(i) = fizzbuzz;
            }
            else if ((i + 1) % 3 == 0)
            {
                result.at(i) = fizz;
            }
            else if ((i + 1) % 5 == 0)
            {
                result.at(i) = buzz;
            }
            else
            {
                result.at(i) = to_string((i + 1));
            }
        }
        return result;
    }
};

// ---
// Test Runner
// ---
template <typename MemFunc, typename Exp, typename... Args>
void runTest(string name, MemFunc func, Exp expected, Args... args)
{
    Solution sol;
    auto result = (sol.*func)(args...);
    bool pass = (result == expected);
    cout << (pass ? "\033[32m[PASS] \033[0m" : "\033[31m[FAIL] \033[0m") << name << endl;
    if (!pass)
    {
        cout << "   Expected: " << toString(expected) << endl;
        cout << "   Got:      " << toString(result) << endl;
    }
}

int main()
{
    // First Test Case
    int input1 = 3;
    vector<string> expected1{"1", "2", "Fizz"};

    // 2nd Test Case
    int input2 = 5;
    vector<string> expected2{"1", "2", "Fizz", "4", "Buzz"};

    // 3rd Test Case
    int input3 = 15;
    vector<string> expected3{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};

    runTest("n = 3", &Solution::fizzBuzz, expected1, input1);
    runTest("n = 5", &Solution::fizzBuzz, expected2, input2);
    runTest("n = 15", &Solution::fizzBuzz, expected3, input3);

    return 0;
}