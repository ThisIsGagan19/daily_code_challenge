// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:

    string removeDups(string str) {
        unordered_map<char,int> mp;
        string ans = "";
        for(char ch : str){
            if(mp.find(ch) == mp.end()){
                ans+= ch;
                mp[ch] = 1;
            }
        }
        return ans;
        
    }
};