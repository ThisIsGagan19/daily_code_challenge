// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> ans;
        istringstream str (s1 + " " + s2);
        while(str >> s1){
            mp[s1]++;
        }

        for(auto it : mp){
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;

    }
};