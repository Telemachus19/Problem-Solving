#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int lower = 0, upper;
    cin >> s;
    int len = s.length();

    for (int i = 0; i < len; i++)
        if (islower(s.at(i)))
            lower++;
    upper = len - lower;
    if (lower >= upper)
    {
        for (int i = 0; i < len; i++)
            s.at(i) = tolower(s.at(i));
    }
    else
    {
        for (int i = 0; i < len; i++)
            s.at(i) = toupper(s.at(i));
    }

    cout << s;
    return 0;
}