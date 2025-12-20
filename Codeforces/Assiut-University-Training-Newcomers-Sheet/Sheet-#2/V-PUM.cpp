#include <iostream>
int main() {
  using namespace std;
  int rows;
  cin >> rows;
  for (int i = 1; i <= rows * 4; i++) {
    if (i % 4 == 0)
      cout << "PUM" << endl;
    else
      cout << i << " ";
  }
}
