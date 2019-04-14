#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class big_int {
    vector<int> num;
public:

    big_int() { num.push_back(0); }

    explicit big_int(int n) {
        while (n) {
            num.push_back(n % 10);
            n /= 10;
        }
        reverse(num.begin(), num.end());
    }

    int get_size() { return num.size(); }

    void multiply(int);

    void print() {
        for (auto d : num)
            cout << d;
        cout << endl;
    }

    void rev() { reverse(num.begin(), num.end()); }

    int get_dig(int idx) { return num[idx]; }
};

void big_int::multiply(int n) {
    int carry = 0, res{};
    for(int i = 0; i < num.size(); i++) {
        res = carry + num[i] * n;
        num[i] = res % 10;
        carry = res / 10;
    }
    while (carry != 0) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    big_int x{1};
    for(int i = 2; i <= 100; i++) {
        x.multiply(i);
    }
    x.rev();
    x.print();
    int sum = 0;
    for(int i = 0; i < x.get_size(); i++)
        sum += x.get_dig(i);
    cout << sum;
    return 0;
}

