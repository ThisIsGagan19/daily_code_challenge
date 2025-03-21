// CODE

class Solution {
    public:
      int findMaxSum(vector<int>& arr) {
          int n = arr.size();
          if(n == 1) return 0;
          if(n == 2) return max(arr[0], arr[1]);
          int prev = arr[0];
          int prev_ka_prev = 0;
          for(int i = 1; i < arr.size(); i++){
              int ans = max(prev, prev_ka_prev + arr[i]);
              prev_ka_prev = prev;
              prev = ans;
          }
          return prev;
      }
  };