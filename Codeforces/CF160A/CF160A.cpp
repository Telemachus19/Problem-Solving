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

using namespace std;

// Typedefs & Macros
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;

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

    int n, coins = 1, first_sum = 0, second_sum = 0;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        a.push_back(value);
    }

    sort(rall(a));

    for (; coins <= n; coins++)
    {
        // first sum
        int i = 0;
        for (; i < coins; i++)
        {
            first_sum += a.at(i);
        }
        for (; i < n; i++)
        {
            second_sum += a.at(i);
        }

        if (first_sum > second_sum)
            break;
        first_sum = 0;
        second_sum = 0;
    }
    cout << coins;
    return 0;
}