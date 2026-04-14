#include <iostream>
#include <string>
using namespace std;

int main() {
    const int character_shift = 32;
    string text;
    cin >> text;
    if (text.at(0) >= 'a' && text.at(0) <= 'z') {
        text.at(0) = text.at(0) - character_shift;
    }
    cout << text;
}