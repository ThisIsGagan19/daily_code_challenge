// TC : O(s.length() * part.length())
// SC : O(linear)

// CODE

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.length();
        for(char ch : s){
            ans.push_back(ch);
            if((ans.length() >= n) && (ans.substr(ans.length() - n) == part)){
                ans.erase(ans.length() - n);
            }
        }
        return ans;
    }
};