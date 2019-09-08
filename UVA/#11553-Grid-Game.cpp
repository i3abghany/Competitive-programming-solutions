#include <iostream>
#include <vector>
#include <algorithm>

constexpr std::size_t max_n = 10;
int mp[max_n][max_n];
int n;

int sum_row(int i) {
    int res = 0;

    for(int j = 0; j < n; j++) {
        res += mp[i][j];
    }

    return res;
}

int sum_col(int j) {
    int res = 0;

    for(int i = 0; i < n; i++) {
        res += mp[i][j];
    }

    return res;
}

int main() {
	int tc; std::cin >> tc;
	while(tc--) {
	    std::cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                std::cin >> mp[i][j];
            }
        }
        std::vector<int> choice(n);
        std::iota(std::begin(choice), std::end(choice), 0);
        int res = std::numeric_limits<int>::max();
        do {
            int curr_sum = 0;
            for(int i = 0; i < n; i++) {
                curr_sum += mp[i][choice[i]];
            }
            res = std::min(res, curr_sum);
        } while(std::next_permutation(std::begin(choice), std::end(choice)));
        std::cout << res << '\n';
	}

    return 0;
}
