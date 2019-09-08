#include <iostream>
#include <cmath>

int main() {
    int N; std::cin >> N;
    while(N--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int x, y, z;
        for(x = -100; x <= 100; x++) {
            for(y = x + 1; y <= 100; y++) {
                z = a - (x + y);
                if(x * y * z == b && std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) == c && x != y && x != z && y != z) {
                    std::cout << x << ' ' << y << ' ' << z << '\n';
                    goto lp;
                }
            }
        }
        std::cout << "No solution.\n";
        lp: 0;
    }
}
