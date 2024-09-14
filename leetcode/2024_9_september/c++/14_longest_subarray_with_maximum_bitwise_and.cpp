// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int len = 0;
        int ans = 0;

        for(auto it : nums){
            if(it == maxi){
                len++;
                ans = max(ans, len);
            }
            else{
                len = 0;
            }
        }
        return ans;
    }
};