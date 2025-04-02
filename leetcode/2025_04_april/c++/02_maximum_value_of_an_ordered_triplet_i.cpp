// CODE

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0;
            long long i = 0;
            long long diff_of_ij = 0;
            for(int k = 0; k < n; k++){
                ans = max(ans, diff_of_ij * nums[k]);
                diff_of_ij = max(diff_of_ij, i - nums[k]);
                i = max(i, static_cast<long long>(nums[k]));
            }
            return ans;
        }
};