#include <iostream>

using namespace std;

int divsum(int N) {
    int res = 1;
    int i;
    for(i = 2; i*i < N; i++)
        if(N % i == 0) {
            res += i;
            res += N / i;
        }
    if(i * i == N)
        res += i;
    return res;
}

int main() {
    constexpr size_t Size = 10000;
    int res = 0;
    for(int i = 1; i <= Size; i++) {
        int sum_divisors = divsum(i);
        if(sum_divisors > i && divsum(sum_divisors) == i)
            res += (i + sum_divisors);
    }
    cout << res;
    return 0;
}
