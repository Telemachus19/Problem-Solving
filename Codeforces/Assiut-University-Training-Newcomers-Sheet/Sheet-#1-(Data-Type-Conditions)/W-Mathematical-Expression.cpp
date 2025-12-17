#include <iostream>
#include <string>
int main() {
  using namespace std;
  int a = 0, b = 0, c = 0;
  string S;
  cin >> a >> S[0] >> b >> S[1] >> c;
  if (S[0] == '+') {
    if (a + b == c)
      cout << "Yes" << endl;
    else
      cout << a + b << endl;
  } else if (S[0] == '-') {
    if (a - b == c)
      cout << "Yes" << endl;
    else
      cout << a - b << endl;
  } else {
    if (a * b == c)
      cout << "Yes" << endl;
    else
      cout << a * b << endl;
  }
  return 0;
}
