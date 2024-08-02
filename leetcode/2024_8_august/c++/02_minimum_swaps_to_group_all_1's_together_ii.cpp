// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) window++;
        }

        if(window == n || window == 0) return 0;

        int ans = INT_MAX;
        int cnt_0 = 0;
        for(int i = 0; i < window + n - 1; i++){
            if(nums[i%n] == 0){
                cnt_0++;
            }
            if(i >= window && nums[i-window] == 0) {
                cnt_0--;
            }
            if(i >= window - 1) {
                ans = min(ans,cnt_0);
            }
        }
        return ans;
    }
};