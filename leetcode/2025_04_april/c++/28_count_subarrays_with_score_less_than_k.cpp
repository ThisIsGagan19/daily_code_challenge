// CODE

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
            long long cnt = 0;
            long long sum = 0;
            int i = 0;
            for(int j = 0; j < n; j++){
                sum += nums[j];
                while(i <= j && (sum * (j-i+1)) >= k){
                    sum -= nums[i];
                    i++;
                }
                cnt += (j-i+1);
            }
            return cnt;
        }
};