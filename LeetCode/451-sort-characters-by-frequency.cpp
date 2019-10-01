#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> mp;
        for (const char i : s) {
            ++mp[i];
        }

        std::sort(std::begin(s), std::end(s), [&mp](const char c, const char b) {
            if(mp[c] == mp[b]) return c > b;
            return mp[c] > mp[b];
        });

        return s;
    }
};
