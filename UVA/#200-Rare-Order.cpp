#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> phrases;

std::vector<std::vector<char>> adj;
std::vector<bool> vis;
std::string res;
std::vector<bool> here;

void dfs(char c) {
    if(vis[c - 'A']) return;

    vis[c - 'A'] = true;
    for(auto n : adj[c - 'A']) {
        dfs(n);
    }
    res.push_back(c);
}

int main(const int argc, const char* argv[]) {
    while (std::cin.peek() != std::char_traits<char>::eof()) {
        std::string s;
        adj.clear(), vis.clear(), res.clear(), phrases.clear(), here.clear();
        here.resize(26, false);
        adj.resize(26, std::vector<char>());
        vis.resize(26, false);
        std::vector<int> indeg(26, 0);
        while (std::cin >> s && s != "#") {
            phrases.push_back(s);
        }

        if (phrases.size() == 1) {
            phrases[0].erase(std::unique(std::begin(phrases[0]), std::end(phrases[0])), std::end(phrases[0]));
            std::cout << phrases[0] << '\n';
            continue;
        }

        for (int i = 0; i < phrases.size(); i++) {
            int j = i + 1;
            if (j >= phrases.size()) break;
            std::size_t mx = std::min(phrases[i].size(), phrases[j].size());
            for (int k = 0; k < mx; k++) {
                auto b = phrases[j][k], a = phrases[i][k];
                if (a != b) {
                    here[a - 'A'] = here[b - 'A'] = true;
                    adj[a - 'A'].push_back(b/* - 'A'*/);
                    indeg[b - 'A']++;
                    break;
                }
            }
        }

        int mn_indeg = std::numeric_limits<int>::max();
        char mn_char = '$';
        for (int i = 0; i < 26; i++) {
            if (here[i] && indeg[i] < mn_indeg) {
                mn_indeg = indeg[i], mn_char = ('A' + i);
            }
        }
        
        // didn't find any connections, which means that the whole testcase is made out of one character.
        if (mn_char == '$') {
            std::cout << phrases[0][0] << std::endl;
            continue;
        }
        
        dfs(mn_char);
        std::reverse(std::begin(res), std::end(res));
        std::cout << (res);
        if(std::cin.peek() != std::char_traits<char>::eof()) {
            std::cout << '\n';
        }
    }
    return 0;
}
