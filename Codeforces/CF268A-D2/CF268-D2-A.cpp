#include <iostream>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <utility>
#include <numeric>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <valarray>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int num_colors = 2;
    int teams;
    int outfits = 0;
    cin >> teams;
    vector<vector<int>> colors(teams, vector<int>(num_colors, 0));

    for (int i = 0; i < teams; i++)
    {
        for (int j = 0; j < num_colors; j++)
        {
            cin >> colors[i][j];
        }
    }
    for (int i = 0; i < teams; i++)
    {
        for (int j = 0; j < teams; j++)
        {
            if (j == i)
                continue;
            if (colors[i][0] == colors[j][1])
                outfits++;
        }
    }
    cout << outfits;

    return 0;
}