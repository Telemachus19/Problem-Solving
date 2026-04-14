#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, i = 0;
    cin >> a >> b;
    while (a <= b)
    {
        i++;
        a *= 3;
        b *= 2;
    }
    cout << i;

    return 0;
}