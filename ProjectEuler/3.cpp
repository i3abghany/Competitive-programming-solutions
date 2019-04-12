#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const long long N = 600851475143;

vector<long long> find_prime_factorization(long long num) {
    vector<long long> primes;
    while(num % 2 == 0) {
        primes.push_back(2);
        num /= 2;
    }
    for(int i = 3; i <= sqrt(num); i += 2) {
        while(num % i == 0) {
            primes.push_back(i);
            num /= i;
        }
    }
    if(num > 2)
        primes.push_back(num);
    return primes;
}

int main() {
    vector<long long> primes = find_prime_factorization(N);
    long long largest_prime = *max_element(primes.begin(), primes.end());
    cout << largest_prime;
}