// CODE

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            }
            else{
                ans = max(ans, i - mp[arr[i]]);
            }
        }
        return ans;
    }
};