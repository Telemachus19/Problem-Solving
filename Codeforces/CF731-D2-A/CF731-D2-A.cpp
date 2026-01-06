#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int moves = 0;
    char current_pos = 'a';
    string s;
    cin >> s;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        int difference = abs(s[i] - current_pos);
        moves += min(difference, 26 - difference);
        current_pos = s[i];
    }
    cout << moves;
    return 0;
}