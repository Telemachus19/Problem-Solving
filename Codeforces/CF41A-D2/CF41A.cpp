#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
#define mp make_pair
#define pb push_back
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define range(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t, result;
    cin >> s >> t;
    reverse(all(s));
    result = (s == t) ? "YES" : "NO";
    cout << result;
    return 0;
}