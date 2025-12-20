#include <iomanip>
#include <iostream>
int main() {
  using namespace std;
  cout << fixed << setprecision(2);
  long double percentage, price;
  cin >> percentage >> price;
  cout << price / (1 - (percentage / 100)) << endl;
}
