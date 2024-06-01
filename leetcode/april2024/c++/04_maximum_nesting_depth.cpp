// CODE

class Solution {
    public:
    int maxDepth(string s) {
        int res = 0, open = 0;
        for(char &c : s) {
            if(c == ')') open--;
            if(c == '(') {
                open++;
                res = max(res, open);
            }
        }
        return res;
    }
};