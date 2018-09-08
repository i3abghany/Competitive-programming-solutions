#include <bits/stdc++.h>
#define n 1000020

using namespace std;

int arr[n];
int comu[n];

void PrimeDigit() {
    int x = 0, cnt = 0;
    for (int i = 2; i < n; i++) {
        int sum = 0;
        if (arr[i] == 0) {
            x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (arr[sum] == 0)
                comu[i] = comu[i - 1] + 1;
            else comu[i] = comu[i - 1];
        } else comu[i] = comu[i - 1];
    }
}

    void seive() {
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i*i <= n; i++) {
        if(arr[i] == 0) {
            for(int j = i * 2; j < n; j += i) {
                arr[j] = 1;
            }
        }
    }
    PrimeDigit();
}


int main() {
    int TC, a, b;
    scanf("%d", &TC);
    seive();
    while(TC--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", comu[b] - comu[a - 1]);
    }

}
