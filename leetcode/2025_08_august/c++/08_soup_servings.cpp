// TC : O(N^2)
// SC : O(N^2)

// CODE

class Solution {
public:
    vector<pair<int,int>> opr {{100,0}, {75,25}, {50,50}, {25,75}};
    vector<vector<double>> dp; // memo
    
    double solve(double a, double b){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0){
            return 1.0;
        }
        if(b <= 0) return 0.0;

        if(dp[a][b] != -1.0) return dp[a][b];
        double prob = 0.0;
        for(auto &it : opr){
            int a_used = it.first;
            int b_used = it.second;

            prob += solve(a-a_used, b-b_used);
        }
        return dp[a][b] = 0.25 * prob;


    }
    double soupServings(int n) {
        if(n >= 5000) return 1; // as the N increases the prob of B empty if decrease and prob A is increases very much and closes to the 1, so return 1
        dp.resize(n+1, vector<double> (n+1, -1.0)); // memo
        return solve(n,n);
    }
};