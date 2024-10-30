// CODE

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto it : arr){
            mp[it]++;
        }
        for(auto it : arr){
            ans += mp[it+k];
        }
        return ans;
    }
};