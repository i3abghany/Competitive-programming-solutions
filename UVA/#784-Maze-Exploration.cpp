#include <iostream>
#include <vector>


std::vector<std::string> mp;

bool valid(int i, int j) {
    if(i < 0 || j < 0) return false;
    if(i >= mp.size()) return false;
    if(j >= mp[i].length()) return false;
    if(mp[i][j] != ' ' && mp[i][j] != '*') return false;
    return true;
}

void dfs(int i, int j) {
    if(!valid(i, j)) {
        return;
    }
    mp[i][j] = '#';

    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main() {

    int tc; std::cin >> tc;
    bool fr = true;
    while(tc--) {
        mp.clear();
        if(fr) {
            std::cin.ignore();
            fr = false;
        }
        int iq = 0;
        std::string line; std::getline(std::cin, line);
        mp.push_back(line);
        while(mp[iq][0] != '_') {
            std::getline(std::cin, line);
            mp.push_back(line);
            iq++;
        }
        mp.pop_back();
        std::pair<int, int> idx;
        for(int i = 0; i < mp.size(); i++) {
            for(int j = 0; j < mp[i].length(); j++) {
                if(mp[i][j] == '*') {
                    idx.first = i, idx.second = j;
                    goto brk;
                }
            }
        }
        brk: dfs(idx.first, idx.second);
        for(int i = 0; i < mp.size(); ++i) {
            for(int j = 0; j < mp[i].length(); ++j) {
                std::cout << mp[i][j];
            }
            std::cout << '\n';
        }
        std::cout << line;
        if(tc) std::cout << '\n';
    }
}
