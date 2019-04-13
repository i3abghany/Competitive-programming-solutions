#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

constexpr size_t limit = static_cast<size_t>(1e6);
bitset<limit> sieve;

bool is_prime(size_t n) {
    return (sieve.test(n));
}

bool circular_prime(size_t n) {
    string s = to_string(n);
    for(int i = 0; i < s.length(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        if(!is_prime(static_cast<size_t>(stoi(s))))
            return false;
    }
    return true;
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
    int res = 0;
    for(size_t i = 2; i < limit; i++) {
        if(sieve.test(i)) {
            if (circular_prime(i))
                res++;
        }
    }
    cout << res;
    return 0;
}
