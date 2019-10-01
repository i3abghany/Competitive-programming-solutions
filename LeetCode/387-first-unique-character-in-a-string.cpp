class Solution {
public:
    int firstUniqChar(std::string s) {
        int arr[26];
        memset(arr, 0, sizeof arr);
        unsigned int sz = s.size();
        for(unsigned int i = 0; i < sz; ++i) {
            ++arr[s[i] - 'a'];
        }
        for(unsigned int i = 0; i < sz; ++i) {
            if(arr[s[i] - 'a'] <= 1) return i;
        }
        return -1;
    }
};
