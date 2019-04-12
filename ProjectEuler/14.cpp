#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

constexpr int limit = static_cast<int>(1e6);
int mem[limit];

int main() {
    memset(mem, -1, sizeof mem);
    mem[1] = 1;
    long long curr;
    int best_num{}, best_len{};
    for(int i = 2; i < limit + 1; i++) {
        curr = i;
        int len = 0;
        while(curr != 1 && curr >= i) {
            len++;
            if(curr & 1)
                curr = curr * 3 + 1;
            else curr = curr / 2;
        }
        mem[i] = len + mem[curr];    
        if(mem[i] > best_len) {
            best_len = mem[i];
            best_num = i;
        }
    }
    cout << best_num;
}
