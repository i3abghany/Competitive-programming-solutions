#include <iostream>
#include <vector>

int main() {
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1, 0);
    std::vector<int> b(n + 1, 0);

    std::vector<int> comu1(n + 1, 0);
    std::vector<int> comu2(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        comu1[i] += comu1[i - 1];
        if (i % 2 == 1) {
            comu1[i] += a[i];
        } else comu1[i] += b[i];
    }

    for(int i = 1; i <= n; i++) {
        comu2[i] += comu2[i - 1];
        if (i % 2 == 1) {
            comu2[i] += b[i];
        } else comu2[i] += a[i];
    }
    for(int i = 0; i < n + 1; i++) {
        std::cout << comu1[i] << ' ';
    }
    std::cout << '\n';
    for(int i = 0; i < n + 1; i++) {
        std::cout << comu2[i] << ' ';
    }
    std::cout << '\n';

    int L, R, mode;
    while(q--) {
        std::cin >> mode >> L >> R;
        if(mode == 1) {
            std::cout << comu1[R] - comu1[L - 1];
        }
        if(mode == 2) {
            std::cout << comu2[R] - comu2[L - 1];
        }
        std::cout << '\n';
    }

    return 0;
}
