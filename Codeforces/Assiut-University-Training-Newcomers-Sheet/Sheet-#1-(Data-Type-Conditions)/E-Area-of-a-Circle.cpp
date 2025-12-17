#include <iomanip>
#include <iostream>
int main() {
  using namespace std;
  cout << fixed << setprecision(9);
  double r;
  cin >> r;
  cout << M_PI * r * r;
}
