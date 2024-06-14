// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                cnt += abs(nums[i] - nums[i-1]) + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return cnt;
    }
};