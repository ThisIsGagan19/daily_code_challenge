// CODE

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int res = 0;
            for(int &n : nums){
                res |= n;
            }
            res = res<<(nums.size() - 1);
            return res;
        }
};