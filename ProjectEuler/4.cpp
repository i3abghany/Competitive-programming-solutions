#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_pal(int n) {
    string num = to_string(n);
    for(int i = 0; i < num.length() / 2; i++)
        if(num[i] != num[num.length() - 1 - i])
            return false;

    return true;
}

int find_largest_palindromic_number() {
    int mx{};
    for(int i = 999; i >= 100; i--) {
        for(int j = 999; j >= 100; j--) {
            if(is_pal(i * j)) {
                mx = max(i * j, mx);
            }
        }
    }
    return mx;
}

int main() {
    cout << find_largest_palindromic_number();
}