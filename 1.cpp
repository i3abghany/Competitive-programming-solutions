#include <iostream>

using namespace std;

const int N = 1000;

int main() {
    int threeSum =    3 * ((N - 1) /  3)  * ((N - 1) /  3 + 1) / 2;
    int fiveSum =     5 * ((N - 1) /  5)  * ((N - 1) /  5 + 1) / 2;
    int fifteenSum = 15 * ((N - 1) / 15)  * ((N - 1) / 15 + 1) / 2;
    cout << threeSum + fiveSum - fifteenSum;
}