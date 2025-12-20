#include <iostream>
int main() {
  using namespace std;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b * c == d)
    cout << "YES";
  else if (a + b - c == d)
    cout << "YES";
  else if (a * b + c == d)
    cout << "YES";
  else if (a * b - c == d)
    cout << "YES";
  else if (a - b + c == d)
    cout << "YES";
  else if (a - b * c == d)
    cout << "YES";
  else
    cout << "NO";
}
