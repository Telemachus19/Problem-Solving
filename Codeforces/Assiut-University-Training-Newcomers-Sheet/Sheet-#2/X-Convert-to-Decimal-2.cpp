#include <cmath>
#include <iostream>
int main() {
  using namespace std;
  int test_cases, n, bin = 0, ones_count = 0;
  cin >> test_cases;
  do {
    cin >> n;
    while (n > 0) {
      if (n % 2 == 1)
        ones_count++;
      n /= 2;
    }
    for (int i = 0; i < ones_count; i++)
      bin += pow(2, i);
    cout << bin << endl;
    bin = 0;
    ones_count = 0;
    test_cases--;
  } while (test_cases > 0);
}
