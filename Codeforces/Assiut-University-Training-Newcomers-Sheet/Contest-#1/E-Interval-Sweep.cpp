#include <iostream>
using namespace std;

int main() {
  int odd, even;
  cin >> odd >> even;
  if (even == odd && odd != 0 && even != 0)
    cout << "YES" << endl;
  else if (odd > even || even > odd) {
    if (odd - even == 1)
      cout << "YES" << endl;
    else if (even - odd == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
}
