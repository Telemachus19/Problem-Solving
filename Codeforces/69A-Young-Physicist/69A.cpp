#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  int x_sum = 0, y_sum = 0, z_sum = 0;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    x_sum += x;
    y_sum += y;
    z_sum += z;
  }
  if (!x_sum && !y_sum && !z_sum) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
