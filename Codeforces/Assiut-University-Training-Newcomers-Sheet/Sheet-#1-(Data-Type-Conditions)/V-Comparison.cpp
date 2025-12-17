#include <iostream>
int main() {
  using namespace std;
  char T;
  int a, b;
  cin >> a >> T >> b;
  if (T == '=') {
    if (a == b)
      cout << "Right" << endl;
    else
      cout << "Wrong" << endl;
  } else if (T == '>') {
    if (a > b)
      cout << "Right" << endl;
    else
      cout << "Wrong" << endl;
  } else {
    if (a < b)
      cout << "Right" << endl;
    else
      cout << "Wrong" << endl;
  }
  return 0;
}
