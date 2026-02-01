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
#include <string>

using namespace std;

// Typedefs & Macros
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

bool checkZeors(ll n)
{
    string s = to_string(n);
    return s.find('0') != string::npos;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin >> t;

    ll n, x;

    while (t--)
    {
        cin >> n >> x;
        ll difference = x - n;
        ll v = -1;

        for (ll i = 0; i < difference; i++)
        {
            if (!checkZeors(n + i))
            {
                v = i;
                break;
            }
        }
        cout << v << "\n";
    }
    return 0;
}