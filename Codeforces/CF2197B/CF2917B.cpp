#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define range(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            ll n;
            cin >> n;

            vector<ll> p(n);
            vector<ll> pos(n + 1);
            for (ll i = 0; i < n; i++)
            {
                cin >> p[i];
                pos[p[i]] = i;
            }
            vector<ll> a(n);
            for (ll i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            bool possible = true;
            ll last_pos = -1;

            for (ll i = 0; i < n; i++)
            {
                if (i == 0 || a[i] != a[i - 1])
                {
                    ll current_pos = pos[a[i]];
                    if (current_pos < last_pos)
                    {
                        possible = false;
                        break;
                    }
                    last_pos = current_pos;
                }
            }

            if (possible)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}