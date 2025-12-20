#include <cmath>
#include <iostream>
int main() {
  using namespace std;
  unsigned int n, k, a;
  long double r;
  int lower_limit = (-2147483648), upper_limit = 2147483647;
  cin >> n >> k >> a;
  if (n % a == 0)
    r = (long double)n / a * k;
  else if (k % a == 0)
    r = (long double)k / a * n;
  else
    r = (long double)n * k / a;
  if (trunc(r) == r) {
    if (r >= lower_limit && r <= upper_limit)
      cout << "int" << endl;
    else
      cout << "long long" << endl;
  } else
    cout << "double" << endl;
}
