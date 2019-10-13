#include <iostream>
#include <vector>
#include <set>

std::vector<std::pair<int, int>> edge_list;
std::vector<std::vector<int>> adj_list;
std::vector<int> start;
std::set<std::pair<int, int>> to_remove;
int timer;

void dfs(int node) {
    start[node] = timer++;
    for (auto const child : adj_list[node]) {
        if (start[child] == -1) {
            dfs(child);
        } else if (start[child] > start[node]) {
            to_remove.insert({node, child});
        }
    }
}

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, m;
    std::cin >> N >> m;

    start.assign(N + 1, -1);
    adj_list.resize(N + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        edge_list.emplace_back(u, v);
    }

    timer = 0;
    dfs(1);

    for (int i = 0; i < edge_list.size(); i++) {
        if (to_remove.find(edge_list[i]) == std::end(to_remove)) {
            std::cout << edge_list[i].first << ' ' << edge_list[i].second << '\n';
        }
    }
}
