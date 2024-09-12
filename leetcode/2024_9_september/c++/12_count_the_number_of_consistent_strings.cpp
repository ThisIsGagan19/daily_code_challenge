// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int cnt = 0;
        for(auto it : allowed){
            s.insert(it);
        }
        
        for(auto it : words){
            bool haiKiNhi = true;
            for(int i = 0; i < it.length(); i++){
                if(s.find(it[i]) == s.end()){
                    haiKiNhi = false;
                    break;
                }
            }
            if(haiKiNhi){
                cnt++;
            }
        }
        return cnt;
        
    }
};