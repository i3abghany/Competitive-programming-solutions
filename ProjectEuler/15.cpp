#include <iostream>

using namespace std;

constexpr int dim = 20;

long long nCr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res *= (2 * dim) - i;
        res /= i + 1;
    }
    return res;
}

int main() {
    cout << nCr(2 * dim, dim);
    return 0;
}
