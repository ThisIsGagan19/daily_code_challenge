// CODE

class Solution {
public:
    int solve(string s, unordered_set<string> &st){
        int maxi = 0;
        for(int i = 1; i <= s.length(); i++){
            string str = s.substr(0,i);
            if(st.find(str) == st.end()){
                st.insert(str);
                maxi = max(maxi, 1 + solve(s.substr(i),st));
                st.erase(str);
            }
        }
        return maxi;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(s,st);
    }
};