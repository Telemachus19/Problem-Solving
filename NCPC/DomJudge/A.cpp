// Standard Headers
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <utility>

using namespace std;

// =========================
// Typedefs & Macros
// =========================
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

// =========================
// Debugging & Testing
// (Only active locally)
// =========================
#ifndef ONLINE_JUDGE

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

template <typename T>
string toString(const T &t)
{
    stringstream ss;
    ss << boolalpha << t;
    return ss.str();
}

template <typename Func, typename Exp, typename... Args>
void runTest(string name, Func func, Exp expected, Args... args)
{
    auto result = func(args...);
    bool pass = (result == expected);
    cout << (pass ? "\033[32m[PASS] \033[0m" : "\033[31m[FAIL] \033[0m") << name << endl;
    if (!pass)
    {
        cout << "   Expected: " << toString(expected) << endl;
        cout << "   Got:      " << toString(result) << endl;
    }
}

#else
#define runTest(...)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    printf("Hello world!");
    return 0;
}