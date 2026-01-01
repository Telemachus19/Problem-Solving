#include <iostream>
using namespace std;
int main()
{
  int n, i = 0, p_count = 0;
  cin >> n;
  bool petya, vasya, tonya;
  do
  {
    cin >> petya >> vasya >> tonya;
    if (petya == 1 && vasya == 1 && tonya == 1)
      p_count++;
    else if (petya == 1 && vasya == 1)
      p_count++;
    else if (vasya == 1 && tonya == 1)
      p_count++;
    else if (tonya == 1 && petya == 1)
      p_count++;
    i++;
  } while (i < n);
  cout << p_count << endl;
}
