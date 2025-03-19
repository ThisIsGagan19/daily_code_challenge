// CODE

class Solution {
    public:
        void palto(vector<int>& nums, int i){
            if(nums[i] == 0) nums[i] = 1;
            else nums[i] = 0;
        }
        int minOperations(vector<int>& nums) {
            int ans = 0;
            int n = nums.size();
            for(int i = 0; i < n - 2; i++){
                if(nums[i] == 0){
                    palto(nums,i);
                    palto(nums,i+1);
                    palto(nums,i+2);
                    ans++;
                }
            }
            // last case handle of n-1 and n-2
            if(nums[n-2] != 1 || nums[n-1] != 1) return -1;
            return ans;
        }
    };