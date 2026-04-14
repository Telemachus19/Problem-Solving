#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, anton = 0, danik = 0;
    cin >> t;

    char *s = new char[t];
    while (t--)
    {
        cin >> s[t];
        if (s[t] == 'A')
            anton++;
        if (s[t] == 'D')
            danik++;
    }
    if (anton > danik)
        cout << "Anton";
    else if (danik > anton)
        cout << "Danik";
    else
        cout << "Friendship";
    return 0;
}