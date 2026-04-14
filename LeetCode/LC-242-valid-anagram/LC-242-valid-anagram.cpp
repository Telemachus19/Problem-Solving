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

bool isAnagram(string s, string t) {
    // hash table for the first string and another hash table for the second string, then compare
    // the two hash tables
    unordered_map<char, int> sCount;
    unordered_map<char, int> tCount;
    for (char c : s) {
        sCount[c]++;
    }
    for (char c : t) {
        tCount[c]++;
    }
    return sCount == tCount;
}

int main() {
    cout << "--- Running Tests ---" << endl;
    // Example:
    // runTest("sample test", isAnagram, expected, arg1, arg2);
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    runTest("s = anagram, t = nagaram", isAnagram, true, s1, t1);
    runTest("s = rat, t = car", isAnagram, false, s2, t2);
    return 0;
}
