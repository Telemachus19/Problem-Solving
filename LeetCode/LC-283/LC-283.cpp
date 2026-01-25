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

// ==========================================
// LeetCode Data Structures & Helpers
// ==========================================
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

// ==========================================
// Solution
// ==========================================
class Solution
{
public:
    vector<int> moveZeroes(vector<int> &nums)
    {
        int nums_size = nums.size();
        for (int NonZero = 0, cur = 0; cur < nums_size; cur++)
        {
            if (nums[cur] != 0)
                swap(nums[NonZero++], nums[cur]);
        }
        return nums;
    }
};

// ==========================================
// Test Runner
// ==========================================
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
    vector<int> input1 = {0, 1, 0, 3, 12};
    vector<int> expect1 = {1, 3, 12, 0, 0};
    runTest("[0, 1, 0, 3, 12]", &Solution::moveZeroes, expect1, input1);
    return 0;
}