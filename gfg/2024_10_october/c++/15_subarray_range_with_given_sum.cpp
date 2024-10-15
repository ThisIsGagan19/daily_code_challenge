// CODE

class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for(auto it : arr){
            sum += it;
            if(mp.count(sum-tar)){
                ans += mp[sum-tar];
            }
            mp[sum] += 1;
        }
        return ans;
    }
};