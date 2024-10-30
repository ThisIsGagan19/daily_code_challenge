// CODE

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // Find longest increasing sequence till an index and store it in an array
        // Find longest increasing sequence from other side as well.
        // to find the ans, we need to traverse and find the element where sum of both the sequence is max (neither of both cannot be 0)
        // Then answer is size-max;
        int n = nums.size();
        vector<int> ans, dpf(n, 0), dpb(n, 0);
        ans.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            if(ans.back() < nums[i]){
                ans.push_back(nums[i]);
                dpf[i] = ans.size()-1;
            } else {
                int pos = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[pos] = nums[i];
                dpf[i] = pos;
            }
        }
        ans.clear();
        ans.push_back(nums[n-1]);
        for(int i = n-2; i>=0; i--){
            if(ans.back() < nums[i]){
                ans.push_back(nums[i]);
                dpb[i] = ans.size()-1;
            } else {
                int pos = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[pos] = nums[i];
                dpb[i] = pos;
            }
        }
        int res = 3;
        for(int i = 1; i<n-1; i++){
            if(dpf[i]!=0 && dpb[i] !=0) res = max(res, dpf[i]+dpb[i]+1);
        }    
        return n-res;
    }
};