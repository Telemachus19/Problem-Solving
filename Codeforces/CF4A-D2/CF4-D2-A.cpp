#include <iostream>
using namespace std;

const unsigned MAX_WEIGHT = 100;

int main() {
    unsigned wght;
    cin >> wght;
    if ((wght >= 4) && (wght <= MAX_WEIGHT) && (wght % 2) == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
