// CODE

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[nums[i] % n] += n;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] / n > 1) res = i;
            nums[i] %= n;
        }
        return res;
    }
};