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

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
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

    int k;
    vector<int> a;
    int total_growth = 0, index = 0;

    cin >> k;
    for (int i = 0; i < 12; i++)
    {
        int v;
        cin >> v;
        a.push_back(v);
    }
    if (k == 0)
    {
        cout << 0;
    }
    sort(rall(a));

    for (int i = 0; i < 12 && k != 0; i++)
    {
        total_growth += a.at(i);
        if (total_growth >= k)
        {
            cout << (i + 1);
            return 0;
        }
    }
    if (total_growth < k)
    {
        cout << -1;
    }
    return 0;
}