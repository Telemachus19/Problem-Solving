#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << setprecision(15);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        double x;

        if (s == "Inf" || s == "+Inf" || s == "inf") {
            x = numeric_limits<double>::infinity();
        } else if (s == "-Inf" || s == "-inf") {
            x = -numeric_limits<double>::infinity();
        } else if (s == "nan" || s == "NaN") {
            x = numeric_limits<double>::quiet_NaN();
        } else {
            x = stod(s);
        }

        cout << 1.0 / x << endl;
    }
}
