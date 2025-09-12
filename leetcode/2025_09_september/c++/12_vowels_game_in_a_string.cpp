// TC = O(N)
// SC = O(1)

// CODE

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt++;
        }
        if(cnt == 0) return false;
        return true;
    }
};