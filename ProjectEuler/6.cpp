#include <iostream>
#include <cmath>

using namespace std;

inline long long integer_summation(int N) {
    return N * (N + 1) / 2;
}

inline long long squares_summation(int N) {
    return N * (N + 1) * (2 * N + 1) / 6;
}

int main() {
    cout << static_cast<long long>(pow(integer_summation(100), 2)) - squares_summation(100);
}