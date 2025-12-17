#include <cmath>
#include <iostream>
int main() {
  using namespace std;
  unsigned long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((log(a) * b) > (log(c) * d))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
