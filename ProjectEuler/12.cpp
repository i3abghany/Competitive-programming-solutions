#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

inline long long triangle_num(int N) {
    return N * (N + 1) / 2;
}

int num_divisors(int N) {
    int res{};
    bool perf = false;
    double tmp = sqrt(N);
    int int_tmp = sqrt(N);
    if(fabs(int_tmp - tmp) < 1e-6)
        perf = true;
    for(int i = 1; i <= sqrt(N); i++) {
        if(N % i == 0) {
            res += 2;
        }
    }
    if(perf)
        res++;
    return res;
}

int main() {
    const int sz = (int)5e6;
    bitset<sz> sieve;
    sieve.flip();
    auto limit = static_cast<size_t>(sqrt(sieve.size()));
    for(size_t i = 2; i <= limit; ++i) {
        if(sieve.test(i)) {
            for(size_t j = i*2; j < sz; j += i)
                sieve.reset(j);
        }
    }

    int N = 1;
    while(true) {
        if(sieve.test(N)) {
            N++;
            continue;
        }
        int tri = triangle_num(N);
        int div = num_divisors(tri);
        if(div > 500) {
            cout << triangle_num(N);
            break;
        }
        N++;
    }
    return 0;
}
