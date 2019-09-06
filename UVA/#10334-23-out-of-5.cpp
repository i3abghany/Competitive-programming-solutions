#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

std::vector<int> p(5);

bool op(int idx, int curr_res) {
    if(idx == 5) return curr_res == 23;
    return op(idx + 1, curr_res + p[idx]) ||
           op(idx + 1, curr_res - p[idx]) ||
           op(idx + 1, curr_res * p[idx]);
}

int main() {
    while(true) {
        p.clear();
        p.resize(5);
        for(int i = 0; i < 5; i++) {
            std::cin >> p[i];
        }
        if(p[0] == 0 and p[1] == 0 and p[2] == 0 and p[3] == 0 and p[4] == 0 and p[5] == 0) {
            break;
        }

        std::sort(std::begin(p), std::end(p));
        do {
            if(op(1, p[0])) {
                std::cout << "Possible\n";
                goto nxt;
            }
        } while(std::next_permutation(std::begin(p), std::end(p)));
        std::cout << "Impossible\n";
        nxt: 0;
    }
    return 0;
}
