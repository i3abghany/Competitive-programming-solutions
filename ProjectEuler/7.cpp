#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

constexpr int N = static_cast<int>(2e5);

int main() {
    bitset<N> sieve;
    sieve.flip();

    size_t limit = static_cast<size_t >(sqrt(sieve.size()) + 1);
    for(size_t i = 2; i < limit; i++) {
        if(sieve.test(i)) {
            for(size_t j = 2 * i; j < N; j += i) {
                sieve.reset(j);
            }
        }
    }
    size_t prime_idx{};
    for(size_t i = 0; i < N; i++) {
        if(prime_idx == 10001) {
            cout << i;
            break;
        }
        if(sieve.test(i))
            prime_idx++;
    }
}