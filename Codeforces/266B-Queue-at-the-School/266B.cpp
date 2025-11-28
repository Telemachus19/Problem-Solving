#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t, str_len;
  string queue;
  cin >> n >> t;
  cin >> queue;
  str_len = queue.length();
  while (t--) {
    for (int i = 0; i < str_len - 1; i++) {
      if (queue[i] == 'B' && queue[i + 1] == 'G') {
        swap(queue[i], queue[i + 1]);
        i++;
      }
    }
  }
  cout << queue << "\n";
  return 0;
}
