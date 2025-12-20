#include <iostream>
unsigned int fib(unsigned int n) {
  unsigned int previous = 0, pprevious = 1;
  unsigned int i = 2, current;
  while (i <= n) {
    current = previous + pprevious;
    pprevious = previous;
    previous = current;
    ++i;
  }
  if (n == 1)
    return 0;
  else
    return current;
}
int main() {
  using namespace std;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << fib(i) << " ";
  }
}
