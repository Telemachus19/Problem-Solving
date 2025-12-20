#include <iostream>
int main() {
  using namespace std;
  long long eyes, mouths, bodies, max = 0;
  cin >> eyes >> mouths >> bodies;
  max += (eyes < mouths) ? eyes : mouths;
  eyes -= max;
  if (eyes > 0)
    max += eyes / 2;
  max = (max < bodies) ? max : bodies;
  cout << max << endl;
  return 0;
}
