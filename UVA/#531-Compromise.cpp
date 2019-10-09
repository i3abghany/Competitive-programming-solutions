#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cstring>

std::unordered_map<std::string, std::size_t> mp1;
std::unordered_map<std::size_t, std::string> mp2;

int main() {
    while (std::cin.peek() != std::char_traits<char>::eof()) {
        mp1.clear(), mp2.clear();
        int t = 0;
        std::string lin;
        std::string txt1, txt2;
        bool first = true;
        while (std::getline(std::cin, lin) && lin != "#") {
            std::istringstream iss(lin);
            std::string word;
            while (iss >> word) {
                if (mp1.find(word) == mp1.end()) {
                    mp1[word] = t++;
                    mp2[t - 1] = word;
                }
                if (first) {
                    first = false;
                } else txt1 += ' ';
                txt1 += word;
            }
        }
        first = true;
        while (std::getline(std::cin, lin) && lin != "#") {
            std::istringstream iss(lin);
            std::string word;
            while (iss >> word) {
                if (mp1.find(word) == mp1.end()) {
                    mp1[word] = t++;
                    mp2[t - 1] = word;
                }
                if (first) {
                    first = false;
                } else txt2 += ' ';
                txt2 += word;
            }
        }

        std::vector<int> t1, t2;
        std::istringstream iss(txt1);
        std::string word;
        while (iss >> word) {
            t1.push_back(mp1[word]);
        }
        iss = std::istringstream{txt2};
        while (iss >> word) {
            t2.push_back(mp1[word]);
        }

        int N = t1.size(), M = t2.size();

        int L[N + 1][M + 1];

        for (int i = 0; i <= N; i++) L[i][0] = 0;
        for (int i = 0; i <= M; i++) L[0][i] = 0;

        int k[N][M];
        memset(k, 0, sizeof k);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    L[i][j] = L[i - 1][j - 1] + 1;
                    k[i - 1][j - 1] = 0;
                } else if (L[i][j - 1] > L[i - 1][j]) {
                    L[i][j] = L[i][j - 1];
                    k[i - 1][j - 1] = 1;
                } else {
                    L[i][j] = L[i - 1][j];
                    k[i - 1][j - 1] = -1;
                }
            }
        }

        if (L[N][M] == -1) {
            std::cout << '\n';
            continue;
        }
        int x = L[N][M] - 1;
        std::vector<std::string> ans(x + 1);
        for (int i = N - 1, j = M - 1;;) {
            if (k[i][j] == 0) {
                ans[x--] = mp2[t1[i]];
                i--;
                j--;
            } else if (k[i][j] == 1) {
                j--;
            } else i--;
            if (i < 0 || j < 0) break;
        }

        for (const auto &item : ans) {
            std::cout << item << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
