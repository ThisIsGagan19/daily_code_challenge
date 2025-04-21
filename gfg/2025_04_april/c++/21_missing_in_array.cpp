// CODE

class Solution {
    public:
      int missingNum(vector<int>& arr) {
          int n = arr.size() + 1;
          int ans = 0;
          for(auto it : arr){
              ans ^= it;
          }
          for(int i = 1; i <= n; i++){
              ans ^= i;
          }
          return ans;
      }
};