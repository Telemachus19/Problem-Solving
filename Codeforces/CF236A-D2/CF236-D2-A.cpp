#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;

    set<char> distinct_chars;
    for (int i = 0; i < s.length(); i++)
    {
        distinct_chars.insert(s[i]);
    }

    if (distinct_chars.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}