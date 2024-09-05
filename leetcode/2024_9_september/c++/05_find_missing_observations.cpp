// TIME COMPEXITY
// O(n) + O(m)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = n + m;
        int sum = 0;
        int totalSum = mean * (total);
        for(int i = 0; i < m; i++){
            sum += rolls[i];
        }

        int missingSum = totalSum - sum;

        if(missingSum > 6 * n || missingSum < n){
            return {};
        }

        vector<int> ans;

        while(n){
            int obv = min(6,missingSum - n + 1);
            ans.push_back(obv);
            missingSum -= obv;
            n -= 1;
        }
        return ans;

    }
};