#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, x;
    cin >> t;

    int officers = 0, crimes = 0;

    while (t--)
    {
        cin >> x;
        officers += x;
        if (officers < 0)
        {
            crimes++;
            officers = 0;
        }
    }
    cout << crimes;
    return 0;
}