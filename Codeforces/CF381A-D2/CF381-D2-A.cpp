#include <iostream>
using namespace std;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, sereja = 0, dima = 0;
    cin >> t;
    int left = 0, right = t - 1;
    int *cards = new int[t];
    for (int i = 0; i < t; i++)
    {
        cin >> cards[i];
    }
    for (int i = 0; i < t; i++)
    {
        if (i % 2 == 0)
        {
            if (cards[left] >= cards[right])
            {
                sereja += cards[left];
                left++;
            }
            else
            {
                sereja += cards[right];
                right--;
            }
        }
        else
        {
            if (cards[left] >= cards[right])
            {
                dima += cards[left];
                left++;
            }
            else
            {
                dima += cards[right];
                right--;
            }
        }
    }
    cout << sereja << " " << dima;
    return 0;
}