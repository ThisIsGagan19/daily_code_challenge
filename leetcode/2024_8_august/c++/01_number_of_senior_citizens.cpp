// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i = 0; i < details.size(); i++){
            int first = details[i][11] - '0';
            int second = details[i][12] - '0';
            int age = first * 10 + second;
            if(age > 60) cnt++;
        }
        return cnt;
        
    }
};