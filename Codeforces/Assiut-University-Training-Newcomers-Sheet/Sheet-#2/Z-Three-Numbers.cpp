#include <iostream>
using namespace std;
int main() {
  int k, s, cnt = 0;
  cin >> k >> s;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++)
      if (s - i - j >= 0 && s - i - j <= k)
        cnt++;
  cout << cnt << endl;
  return 0;
}
