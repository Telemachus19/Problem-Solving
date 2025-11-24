#include <iostream>
using namespace std;
int main() {
  int n, i = 0, p_count = 0;
  cin >> n;
  bool Petya, Vasya, Tonya;
  do {
    cin >> Petya >> Vasya >> Tonya;
    if (Petya == 1 && Vasya == 1 && Tonya == 1)
      p_count++;
    else if (Petya == 1 && Vasya == 1)
      p_count++;
    else if (Vasya == 1 && Tonya == 1)
      p_count++;
    else if (Tonya == 1 && Petya == 1)
      p_count++;
    i++;
  } while (i < n);
  cout << p_count << endl;
}
