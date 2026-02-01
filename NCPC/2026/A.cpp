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

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string first_name;
    string last_name;
    cin >> first_name >> last_name;
    transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);
    cout << (char)tolower(first_name[0]) << last_name << "@noon.com";
    return 0;
}