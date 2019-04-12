#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

const size_t sz = static_cast<size_t>(2e6);

int main() {
    bitset<sz> sieve;
    sieve.flip();
    auto limit = static_cast<size_t>(sqrt(sieve.size()));
    for(size_t i = 2; i <= limit; ++i) {
        if(sieve.test(i)) {
            for(size_t j = i*2; j < sz; j += i)
                sieve.reset(j);
        }
    }
    long long sum{};
    for(size_t i = 2; i < sz; i++) {
        if(sieve.test(i)) {
            sum += i;
        }
    }
    cout << sum;
}