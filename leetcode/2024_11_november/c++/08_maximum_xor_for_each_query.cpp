// CODE

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mx=(pow(2,maximumBit)-1);
        int n=nums.size();
        nums[0]=(nums[0] xor mx);
        for(int i=1;i<n;i++){
            nums[i]=(nums[i-1] xor nums[i]);
        }
        reverse(begin(nums),end(nums));
        return nums;
    }
};