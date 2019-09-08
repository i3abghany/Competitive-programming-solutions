#include <iostream>
#include <vector>

bool check(int a, int b) {
    std::string num1 = std::to_string(a), num2 = std::to_string(b);
    while(num1.length() < 5) num1 = "0" + num1;
    if(num2.length() < 5) num2 = "0" + num2;
    bool tru = true;
    int arr[] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(auto &ch : num1) arr[ch - '0' - 1]++;
    for(auto &ch : num2) arr[ch - '0' - 1]++;

    for(int p : arr) tru &= (p == 1);
    return tru;
}

constexpr double EPS = std::numeric_limits<double>::epsilon() * 1000000;

int main() {
    int Nn;
    std::vector<int> Ns;
    while(std::cin >> Nn && Nn != 0) Ns.push_back(Nn);
    for(int i = 0; i < Ns.size(); i++) {
        int N = Ns[i];
        std::vector<std::pair<int, int>> p;
        p.clear();
        // num1 = N * num2;
        for (int num1 = 01234; num1 < 99999; num1++) {
            double num2 = num1 * 1.0 / N;
            if (num2 - int(num2) > EPS) continue;
            if (check(num1, int(num2))) {
                p.emplace_back(num1, num2);
            }
        }
        if(p.empty()) {
            std::cout << "There are no solutions for " << N << ".\n";
        }
        for (auto pr : p){
            auto num1 = std::to_string(pr.first);
            auto num2 = std::to_string(pr.second);
            while(num1.length() < 5) num1 = "0" + num1;
            while(num2.length() < 5) num2 = "0" + num2;
            std::cout << num1 << " / " << num2 << " = " << N << '\n';

        }
        if(i < Ns.size() - 1) std::cout << '\n';
    }

    return 0;
}
