#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int Ca, Cb, req;
struct state {int a, b, action;};
constexpr std::size_t nax = 1000 + 2;
state prev[nax][nax];
bool vis[nax][nax];

std::queue<state> Q;
                                                     //  pour into B, pour into A
enum Action : uint8_t {FILL_A, FILL_B, EMPTY_A, EMPTY_B, POUR_B,      POUR_A,      START};
std::string acts[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A", "Start"};
void print_path(state curr) {
    if(curr.a == 0 && curr.b == 0) {
        return;
    }

    print_path(prev[curr.a][curr.b]);
    std::cout << acts[curr.action] << '\n';
}

void add_state(int a, int b, Action act, state parent) {
    if(vis[a][b]) {
        return;
    }
    state curr = {a, b, act};
    Q.push(curr);
    prev[a][b] = parent;
    vis[a][b] = true;
}

void bfs(int x, int y) {
    Q = std::queue<state>();
    memset(vis, 0, sizeof vis);

    add_state(0, 0, Action::START, state{});

    while(!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        int a = curr.a, b = curr.b;
        if(b == req) {
            print_path(curr);
            std::cout << "success\n";
            return;
        }
        
        add_state(Ca, b, FILL_A, curr);
        add_state(a, Cb, FILL_B, curr);

        add_state(0, b, EMPTY_A, curr);
        add_state(a, 0, EMPTY_B, curr);

        // pour from b to a.
        int next_a = (a + b) > Ca ? Ca : a + b;
        int next_b = (a + b) > Ca ? (a +  b) - Ca : 0;

        add_state(next_a, next_b, POUR_A, curr);

        // pour from a to b.
        next_a = (a + b) > Cb ? (a +  b) - Cb : 0;
        next_b = (a + b) > Cb ? Cb : a + b;

        add_state(next_a, next_b, POUR_B, curr);
    }
}

int main() {

    while(std::cin >> Ca >> Cb >> req) {
        bfs(0, 0);
    }
    
    return 0;
}
