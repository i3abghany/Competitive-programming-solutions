#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

#define watch(a) std::cout << #a << ": " << a
template<typename C>
std::ostream &operator<<(const std::ostream &out, const C &cont) {
    std::cout << "[";
    const std::size_t sz = cont.size();
    for (int i = 0; i < sz; i++) {
        std::cout << *(std::begin(cont) + i);
        if (i != sz - 1) std::cout << ", ";
        else std::cout << "]\n";
    }
}
template<typename A, typename B>
std::ostream &operator<<(const std::ostream &out, const std::pair<A, B> &p) {
    std::cout << "{" << p.first << ", " << p.second << "}\n";
}

std::vector<std::string> perms;

void print_perm(int len, std::string a) {
    if(len == 0) {
        return;
    }
    print_perm(len - 1, a + "L");
    print_perm(len - 1, a + "R");
    perms.push_back(a);
}
std::string get_root(const std::string& pos) {
    if(pos.size() == 1) return "ROOT";
    return pos.substr(0, pos.size() - 1);
}

// L R LL LR RL RR LLL LLR LRL LRR RLL RLR RRL RRR
bool cmp(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

int main(const int argc, const char* argv[]) {
    std::string lin, tree_str;
    std::map<std::string, int> tree;
    constexpr std::size_t max_level = 15;
    print_perm(max_level + 1, "");
    std::stable_sort(std::begin(perms), std::end(perms), cmp);
    perms[0] = "ROOT";
    while (std::cin.peek() != std::char_traits<char>::eof()) {
        tree.clear(), lin.clear(), tree_str.clear();
        while (std::getline(std::cin, lin) && lin.find("()") == std::string::npos) {
            tree_str += lin;
        }
        tree_str += (" " + lin + " ");
        tree_str.erase(tree_str.find("()"), 2);
        std::istringstream iss(tree_str);
        std::string node_pair;
        std::size_t height = 0;
        while (iss >> node_pair) {
            const auto sz1 = node_pair.find('(') + 1;
            const auto sz2 = node_pair.find(',') - sz1;
            const auto num_str = node_pair.substr(sz1, sz2);
            const int node_data = std::stoi(num_str);
            if (node_pair.find(",)") != std::string::npos) tree["ROOT"] = node_data;
            else {
                const auto idx = node_pair.find(',') + 1;
                const auto len = node_pair.find(')') - idx;
                const std::string pos = node_pair.substr(idx, len);
                tree[pos] = node_data;
                height = std::max(height, pos.size());
            }
        }
        bool flag = false;
        const int perm_num = static_cast<int>(std::pow(2, height));
        for(const auto &p : tree) {
            if(p.first == "ROOT") continue;
            if(tree.find(get_root(p.first)) == std::end(tree)) {
                std::cout << "not complete\n";
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else {
            for (int i = 0; (!i || perms[i].size() <= height); i++) {
                const std::string perm = perms[i];
                if (tree.find(perm) == std::end(tree)) {
                    continue;
                } else {
                    std::cout << tree[perm];
                    if(!i || perms[i + 1].size() < height) std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
    }

    return 0;
}
