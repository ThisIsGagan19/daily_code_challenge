// CODE

class Solution {
    public:
    bool checkValidString(string s) {
        int n = s.size() - 1, open = 0, close = 0;
        for(int i = 0; i <= n; i++) {
            if(s[i] == '(' or s[i] == '*') open++;
            else open--;
            if(s[n - i] == ')' or s[n - i] == '*') close++;
            else close--;
            if(open < 0 or close < 0) return 0;
        }
        return 1;
    }
};