#include <iostream>
int main() {
  using namespace std;
  long long a = 0, b = 0, k = 0;
  cin >> a >> b >> k;
  if (a % k == 0 && b % k == 0)
    cout << "Both" << endl;
  else if (a % k == 0 && b % k != 0)
    cout << "Memo" << endl;
  else if (a % k != 0 && b % k == 0)
    cout << "Momo" << endl;
  else if (a % k != 00 && b % k != 0)
    cout << "No One" << endl;
  return 0;
}
