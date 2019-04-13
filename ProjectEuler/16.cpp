#include <iostream>
#include <algorithm>

using namespace std;


string sum_big_ints(string str1, string str2) {
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
}

int sum_cells(string s) {
    int res = 0;
    for(auto d : s)
        res += (d - '0');
    return res;
}

int main() {
    string num = "2";
    int num_iter = 999;
    while(num_iter--) {
        num = sum_big_ints(num, num);
    }
    cout << sum_cells(num);
    return 0;
}
