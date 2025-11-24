#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, count = 0;
  string s;
  cin >> n;
  do {
    cin >> s;
    if (s.length() > 10) {
      cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
    } else
      cout << s << endl;
    count++;

  } while (count < n);
  return 0;
}
