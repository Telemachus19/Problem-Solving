#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const char red = 'R';
    const char green = 'G';
    const char blue = 'B';
    char current = '\0', previous = '\0';
    // Red, Green, Blue
    int counter[3] = {0, 0, 0};

    string s;
    cin >> s;

    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        current = s.at(i);
        if (current == previous)
        {
            switch (current)
            {
            case red:
                counter[0]++;
                break;
            case green:
                counter[1]++;
                break;
            case blue:
                counter[2]++;
                break;
            }
        }
        previous = current;
    }
    cout << counter[0] + counter[1] + counter[2];

    return 0;
}