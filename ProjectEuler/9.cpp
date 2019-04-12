#include <iostream>
#include <cmath>
#include <bitset>
#include <ctime>
#include <numeric>

using namespace std;

const int limit = 1000;
const double eps = 1e-5;

int main() {
    bool f = false;
    int a{}, b{}, c{};
    for(a = 1; a < limit; a++) {
        for(b = a; b < limit / 2; b++) {
            c = static_cast<int>(sqrt(pow(a, 2) + pow(b, 2)));
            double d = sqrt(pow(a, 2) + pow(b, 2));
            if(fabs(d - c) > eps) {
                continue;
            }
            if(a + b + c == limit) {
                f = true;
                break;
            }
        }
        if(f) break;
    }
    cout << a * b * c << endl;
    cout << a << " " << b << " " << c;
}