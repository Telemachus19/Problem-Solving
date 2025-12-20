#include <iostream>
int main() {
  using namespace std;
  char c, print;
  cin >> c;
  print = c + 1;
  if (print != '{')
    cout << print << endl;
  else
    cout << 'a' << endl;
}
