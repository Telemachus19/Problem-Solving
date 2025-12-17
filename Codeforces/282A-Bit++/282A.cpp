#include <iostream>
int main() {
  using namespace std;
  int t = 0, x = 0;
  string c;
  cin >> t;
  while (t > 0) {
    cin >> c;
    for (int i = 0; i < 3; i++)
      if (c[i] == '+') {
        x++;
        break;
      } else if (c[i] == '-') {
        x--;
        break;
      }
    t--;
  }
  cout << x << endl;
  return 0;
}
