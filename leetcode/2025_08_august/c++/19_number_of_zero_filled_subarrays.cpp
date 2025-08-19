// TC : O(N)
// SC : O(1)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        // approach 1 -> simple math
        long long ans = 0;
        int n = nums.size();
        int i = 0;
        while( i < n){
            long long cnt = 0;
            if(nums[i] == 0){
                while(i < n && nums[i] == 0){
                    i++;
                    cnt++;
                }
            }
            else{
                i++;
            }
            ans += cnt*(cnt+1) / 2;
        }
        return ans;

        // approach 2 -> clean observation
        long long ans = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};