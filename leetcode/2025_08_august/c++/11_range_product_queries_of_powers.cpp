// TC : O(N)
// SC : O(1)

// CODE

class Solution {
public:
    int MOD = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>power;
        vector<int> res;
        // power array ban gya h
        for(int i = 0; i < 32; i++){
            if((n & (1<<i)) != 0){
                power.push_back((1<<i));
            }
        }

        // query wale pe loop lagao
        for(auto it : queries){
            int s = it[0];
            int e = it[1];
            long product = 1;
            for(int i = s; i <= e; i++){
                product = (product * power[i]) % MOD;
            }
            res.push_back(product);
        }
        return res;
    }
};