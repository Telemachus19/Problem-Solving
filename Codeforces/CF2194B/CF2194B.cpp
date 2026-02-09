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
    cin >> t;

    while (t--)
    {
        ull n, x, y, s = 0, maximumTransferAmount = 0;
        cin >> n >> x >> y;
        vector<ull> a(n);

        for (ull i = 0; i < n; i++)
        {
            cin >> a[i];
            s += (a[i] / x) * y;
        }
        for (ull j = 0; j < n; j++)
        {
            ull reciverTotal = s - ((a[j] / x) * y) + a[j];
            maximumTransferAmount = max(maximumTransferAmount, reciverTotal);
        }

        cout << maximumTransferAmount << endl;
    }

    return 0;
}