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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 4e18;

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
        ld x_a, y_a, x_g, y_g, d, s, result;

        cin >> x_a >> y_a;
        cin >> x_g >> y_g;
        cin >> s;
        d = sqrtl(((x_a - x_g) * (x_a - x_g)) + ((y_a - y_g) * (y_a - y_g)));
        result = powl((sqrtl(s) - d), 2) / 2;
        printf("%.6Lf\n", result);
    }

    return 0;
}