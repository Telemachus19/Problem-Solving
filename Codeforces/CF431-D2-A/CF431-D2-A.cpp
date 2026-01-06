#include <iostream>
#include <string>
using namespace std;
#define SIZE 4
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[SIZE];
    unsigned long long calorie = 0;
    for (int i = 0; i < SIZE; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        calorie += a[(s.at(i) % 48) - 1];
    }
    cout << calorie;
    return 0;
}