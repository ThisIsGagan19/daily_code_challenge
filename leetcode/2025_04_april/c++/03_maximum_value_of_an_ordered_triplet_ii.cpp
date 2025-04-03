// CODE

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0;
            long long i = 0;
            long long diff = 0;
    
            for(int k = 0; k < n; k++){
                ans = max(ans, diff * nums[k]);
                diff = max(diff, i - nums[k]);
                i = max(i, static_cast<long long>(nums[k]));
            }
            return ans;
        }
    };
    