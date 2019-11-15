#include <iostream>
#include <vector>

using namespace std;

vector<int> pos;
vector<int> nums;

int k; 
constexpr int r = 6;

void ez(int depth, int margin) {
    if(depth >= r) {
        for(int i = 0; i < r - 1; i++) {
            cout << pos[i] << ' ';
        }
        cout << pos[r - 1] << endl;
        return;
    }

    if(nums.size() - margin < r - depth) {
        return;
    }

    for(int i = margin; i < k; i++) {
        pos[depth] = nums[i];
        ez(depth + 1, i + 1);
    }
}

int main() {
    freopen("out.txt", "w", stdout);
    while(cin >> k && k) {
        nums.clear(); nums.resize(k);
        pos.clear(); pos.resize(r);
        for(auto &el : nums) cin >> el;
        ez(0, 0);
        cout << endl;
    }

}

