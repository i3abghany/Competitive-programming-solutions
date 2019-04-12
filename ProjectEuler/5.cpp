#include <iostream>
#include <numeric>

using namespace std;

int LCM(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int res{1};
    for(int i = 1; i < 20; i++)
        res = LCM(res, i);
    cout << res;
}