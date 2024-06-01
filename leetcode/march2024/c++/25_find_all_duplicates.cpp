// INTUITION
// Try to mark the visited values with something and when visited again 
// we get our result. Hint - change their sign

// CODE

class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if (nums[abs(nums[i]) - 1] < 0) res.push_back(abs(nums[i]));
            else nums[abs(nums[i]) - 1] *= -1;
        }
        return res;
    }
};