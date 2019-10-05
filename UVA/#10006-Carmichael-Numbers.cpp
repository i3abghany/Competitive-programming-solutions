#include <iostream>
#include <vector>

constexpr std::size_t nax = 65000 + 4;
std::vector<bool> prime(nax, true);

void sieve(const std::size_t n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < n; j += i)
                prime[j] = false;
        }
    }
}

long long poww(long long b, long long p, long long m) {
    if (p == 0)
        return 1;

    long long res = poww(b, p / 2, m);
    res = ((res % m) * (res % m)) % m;

    if (p % 2 != 0)
        res = ((res % m) * (b % m)) % m;

    return res;
}

int main() {
    int n;
    sieve(65001);
    while (std::cin >> n && n) {
        if (!prime[n] && poww(2, n, n) == 2 && poww(3, n, n) == 3 && poww(5, n, n) == 5) {
            std::cout << "The number " << n << " is a Carmichael number.\n";
        }
        else {
            std::cout << n << " is normal.\n";
        }
    }
    return 0;
}
