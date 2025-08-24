// TC : O(N)
// SC : O(1)

// CODE

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int last_zero_index = -1;
        int j = 0;
        int res = 0;
        while(j < n){
            if(nums[j] == 0){
                i = last_zero_index + 1;
                last_zero_index = j;
            }
            res = max(res,j-i);
            j++;
        }
        return res;
    }
};