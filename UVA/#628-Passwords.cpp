#include <iostream>
#include <vector>

std::vector<int> nums(10);
std::vector<std::string> dict;
std::vector<std::string> rules;

void eval_rule(int rule_idx, int char_idx, const std::string& curr = "") {
    if (char_idx == rules[rule_idx].length()) {
        std::cout << curr << '\n';
        return;
    }
    if (rules[rule_idx][char_idx] == '#') {
        for (std::string &wo : dict) {
            eval_rule(rule_idx, char_idx + 1, curr + wo);
        }
    } else if (rules[rule_idx][char_idx] == '0') {
        for (int num : nums) {
            eval_rule(rule_idx, char_idx + 1, curr + std::to_string(num));
        }
    }
}

int main() {
    freopen("C:\\Users\\pi\\Desktop\\planz.txt", "r", stdin);
    freopen("C:\\Users\\pi\\Desktop\\out.txt", "w", stdout);
    int n;
    int i = 0;
    for (int& el : nums) el = i++;
    std::cin >> n;
    while (true) {
        std::cout << "--\n" ;
        dict.clear();
        dict.resize(n);
        for (std::string& el : dict) std::cin >> el;
        int m; std::cin >> m;
        rules.clear();
        rules.resize(m);
        for (std::string& el : rules) std::cin >> el;
        for(int iz = 0; iz < m; iz++) {
            eval_rule(iz, 0);
        }
        if(!(std::cin >> n)) break;
    }
    return 0;
}
