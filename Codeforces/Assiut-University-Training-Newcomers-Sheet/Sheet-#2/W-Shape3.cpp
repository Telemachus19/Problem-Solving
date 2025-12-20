#include <iostream>
using namespace std;
void space(int n) {
  for (int i = 0; i < n; i++)
    cout << " ";
}
int main() {
  int rows;
  cin >> rows;
  for (int i = 0; i < rows; i++) {
    space(rows - i - 1);
    for (int z = 0; z <= i; z++) {
      if (z == 0)
        cout << "*";
      else
        cout << "**";
    }
    cout << endl;
  }
  for (int i = 0; i < rows; i++) {
    space(i);
    for (int z = rows; z > i; z--) {
      if (z == i + 1)
        cout << "*";
      else
        cout << "**";
    }
    cout << endl;
  }
}
