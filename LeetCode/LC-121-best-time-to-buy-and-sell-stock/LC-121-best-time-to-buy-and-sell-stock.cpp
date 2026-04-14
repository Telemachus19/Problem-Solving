#include <climits>
#include <iostream>
#include <sstream>
#include <string>
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

int maxProfit(vector<int>& prices) {
    // two pointers
    int l = 0;
    int r = 1;
    int maxProfit = 0;
    while (r < prices.size()) {
        if (prices[r] > prices[l]) {
            // Update max profit if current profit is greater
            maxProfit = max(maxProfit, prices[r] - prices[l]);
        } else {
            // Move left pointer to current right pointer
            l = r;
        }
        r++;
    }
    return maxProfit;
}

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", maxProfit, expected, arg1);
    vector<int> prices1{2, 4, 1};
    runTest("prices1: {2,4,1}, maxProfit = 2", maxProfit, 2, prices1);
    return 0;
}
