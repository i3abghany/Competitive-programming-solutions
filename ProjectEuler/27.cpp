#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

constexpr size_t limit = static_cast<size_t>(1e6);
bitset<limit> sieve;

bool is_prime(int n) {
    return (sieve.test(n));
}

int func(int a, int b, int N) {
    int res = N*N + N*a + b;
    return res;
}

int gen_primes(int a, int b) {
    int res = 0;
    while(true) {
        if(func(a, b, res) < 0)
            return 0;
        if(is_prime(func(a, b, res))) {
            res++;
        } else {
            return res;
        }
    }
}

int main() {
    sieve.flip();
    size_t sz = static_cast<size_t>(sqrt(limit)) + 1;
    for(size_t i = 2; i < sz; i++) {
        if(sieve.test(i)) {
            for(size_t j = i * 2; j < limit; j += i)
                sieve.reset(j);
        }
    }
    int max = 0, maxA = 0, maxB = 0;
    int a = -1000, b = -1000;
    for(a = -1000; a <= 1000; a++) {
        for(b = -1000; b <= 1000; b++) {
            int res = gen_primes(a, b);
            if(res > max) {
                max = res;
                maxA = a, maxB = b;
            }
        }
    }
    cout << maxA * maxB;
}

