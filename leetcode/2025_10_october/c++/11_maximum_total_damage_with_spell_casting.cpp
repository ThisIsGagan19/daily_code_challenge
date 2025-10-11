// TC = O(N + MlogM) // M -> size of new vector without duplicates 
// SC = O(M)

// CODE

class Solution {
public:
    long long solve(int ind, vector<int>& p, unordered_map<int,int>& mp, vector<long long>& dp){
        if(ind >= p.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        // find lowerbound ind of p[ind] + 3;
        auto it = lower_bound(p.begin(), p.end(), p[ind] + 3); // it points to index of p[ind]+3
        int index = it - p.begin();
        // pick
        long long int pick = ((long long)p[ind] * 1LL * (long long)mp[p[ind]]) + solve(index,p,mp,dp);
        // not pick
        long long int notPick = solve(ind+1,p,mp,dp);

        return dp[ind] = max(pick,notPick);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> mp;
        for(auto it : power){
            mp[it]++;
        }
        vector<int> p;
        for(auto it : mp){
            p.push_back(it.first);
        }

        vector<long long> dp(p.size(),-1);

        sort(p.begin(), p.end());

        return solve(0,p,mp,dp);
    }
};