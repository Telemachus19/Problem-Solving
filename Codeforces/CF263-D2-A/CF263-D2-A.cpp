#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int matrix[5][5];
  int r, c, steps = 0, distance = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1)
      {
        r = i;
        c = j;
      }
    }
  }
  if (r < 2)
    distance += (2 - r);
  else
    distance += (r - 2);
  if (c < 2)
    distance += (2 - c);
  else
    distance += (c - 2);
  cout << distance << endl;
  return 0;
}
