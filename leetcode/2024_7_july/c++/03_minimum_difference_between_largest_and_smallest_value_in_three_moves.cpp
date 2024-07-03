// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5) return 0;

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 4;
        int res = INT_MAX;

        for(; i < 4; i++, j++){
            res = min(res, abs(nums[j] - nums[i]));
        }

        return res;
    }
};