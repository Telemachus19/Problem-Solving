#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, groups = 0;
    string current, prev = "";
    cin >> n;
    while (n--)
    {
        cin >> current;
        if (current.compare(prev) != 0)
            groups++;
        prev = current;
    }
    cout << groups;
    return 0;
}