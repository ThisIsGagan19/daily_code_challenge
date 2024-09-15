// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> mp = {{'a',1}, {'e',2}, {'i',4}, {'o',8}, {'u',16}};
        vector<int> bitset(32,-1);
        int mask = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            mask = mask ^ mp[s[i]];
            if(mask != 0 && bitset[mask] == -1){
                bitset[mask] = i;
            }
            maxLen = max(maxLen, i - bitset[mask]);
        }

        return maxLen;
    }
};