#include <iostream>

using namespace std;
int main()
{
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, temp, res = 0;
    cin >> n >> h;
    while (n--)
    {
        cin >> temp;
        res += (temp <= h) ? 1 : 2;
    }
    cout << res;
    
    return 0;
}