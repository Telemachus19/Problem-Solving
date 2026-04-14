#include <iostream>
#include <sstream>
#include <stack>
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

class MinStack {
  public:
    stack<int> main;
    stack<int> min;
    MinStack() {}

    void push(int val) {
        main.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        } else {
            min.push(min.top());
        }
    }

    void pop() {
        if (!main.empty()) {
            main.pop();
            min.pop();
        }
    }

    int top() { return main.top(); }

    int getMin() { return min.top(); }
};

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", solve, expected, arg1);
    return 0;
}
