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

bool isPalindrome(int x) {
    int y = x;
    long long r = 0;
    while (y > 0) {
        r = r * 10 + y % 10;
        y /= 10;
    }
    return (r == x);
}

int main() {
    cout << "--- Running Tests ---" << endl;
    runTest("x = 121", isPalindrome, true, 121);
    runTest("x = -121", isPalindrome, false, -121);
    runTest("x = 10", isPalindrome, false, 10);
    return 0;
}
