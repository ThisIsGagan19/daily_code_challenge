// INTUITION
// Standard Sliding Window Problem

// CODE

class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int start = 0, end = 0;
        unordered_map<int, int> count;

        while(end < n) {
            count[nums[end]]++;
            while(count.size() > k) {
                count[nums[start]]--;
                if(count[nums[start]] == 0)
                    count.erase(nums[start]);
                start++;
            }
            res += (end - start + 1);
            end += 1;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};