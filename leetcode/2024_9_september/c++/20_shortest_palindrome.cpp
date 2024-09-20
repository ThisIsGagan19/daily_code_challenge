// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    int kmp(string s){
        int n = s.length();
        int i = 0;
        vector<int> lps(n+1,0);
        for(int j = 1; j < n; j++){
            while(i > 0 && s[i] != s[j]){
                i = lps[i-1];
            }
            if(s[i] == s[j]){
                i++;
            }
            lps[j] = i;
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string newStr = s + "#" + rev;

        int len = kmp(newStr);
        string rem = s.substr(len);
        reverse(rem.begin(), rem.end());
        return rem + s;
    }
};