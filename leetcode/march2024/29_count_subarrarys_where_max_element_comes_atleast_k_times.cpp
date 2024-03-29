// CODE

class Solution {
    public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxiboi = *max_element(nums.begin(), nums.end());
        int n = nums.size(), start = 0, end = 0;
        long long res = 0;
        while(end < n) {
            if(nums[end] == maxiboi) k--;
            while(k == 0) {
                if(nums[start] == maxiboi) k++;
                start++;
            }
            res += start;
            end++;
        }
        return res;
    }
};