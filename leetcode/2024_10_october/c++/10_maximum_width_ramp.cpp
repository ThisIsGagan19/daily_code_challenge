// CODE

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> max_right(nums.size(), 0);
        max_right[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            max_right[i] = max(max_right[i+1], nums[i]);
        }

        int ans = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            while(nums[l] > max_right[r]){
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};