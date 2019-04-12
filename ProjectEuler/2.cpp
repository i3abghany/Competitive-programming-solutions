#include <iostream>
#include <cstring>

using namespace std;

const int N = 40;
int fib[N];

int fibonacci(int n) {
    if(n < 1)
        return 1;
    if(fib[n - 1] == -1)
        return fib[n - 1] = fibonacci(n - 1) + fibonacci(n - 2);
    else return fib[n - 1];
}

int main() {
    memset(fib, -1, sizeof(fib));
    fib[0] = 0, fib[1] = 1;
    fibonacci(40);
    long long sum{};
    for(int i = 0; i < N; i++)
        if(fib[i] < 4e6 && fib[i] % 2 == 0)
            sum += fib[i];
    cout << sum;
}