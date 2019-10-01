#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res;

        std::map<int, int> mp;
        for(auto num : nums) ++mp[num];

        std::vector<std::pair<int, int>> vp(mp.begin(), mp.end());
        std::sort(vp.begin(), vp.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++) {
            res.push_back(vp[i].first);
        }
        return res;        
    }
};
