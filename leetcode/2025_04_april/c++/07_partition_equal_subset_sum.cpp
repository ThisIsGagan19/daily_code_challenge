// CODE

class Solution {
    public:
        // recursion will give TLE use memo
        // TC = O(n * tar)
        // SC = O(n * tar)
        bool solve(int i, vector<int>& nums, int tar, vector<vector<int>>& dp){
            if(tar == 0) return true;
            if(i >= nums.size()) return false;
            if(dp[i][tar] != -1) return dp[i][tar];
    
            // tar - nums[i] can be negative so execute only when positive so use if
            bool take = false; // koi gurantee nhi h toh false hoga true nhi
            if(tar - nums[i] >= 0){
                take = solve(i+1,nums,tar-nums[i],dp);
            }
            bool notTake = solve(i+1,nums,tar,dp);
            return dp[i][tar] = (take || notTake);
        }
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            int n = nums.size();
            for(auto it : nums){
                sum += it;
            }
            if(sum % 2 != 0) return false;
    
            int tar = sum / 2;
            vector<vector<int>> dp(n+1, vector<int> (tar+1, -1));
            return solve(0,nums,tar,dp);
    
        }
};