#include <iostream>
int main() {
  using namespace std;
  int a, b, c, d, e;
  cin >> a >> b >> c >> d;
  e = ((a % 100) * (b % 100) * (c % 100) * (d % 100)) % 100;
  if (e < 10)
    cout << 0 << e;
  else
    cout << e;
}
