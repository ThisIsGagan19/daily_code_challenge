// CODE

class Solution {
    public:
      int solve(int idx, vector<int>& arr){
          int n = arr.size();
          int prev2 = 0, prev1 = arr[idx];
          
          for(int i = idx+1; i < n; ++i){
              int curr = max(arr[i]+prev2, prev1);
              prev2 = prev1;
              prev1 = curr;
          }
          return prev1;
      }
      int maxValue(vector<int>& arr) {
          int last = solve(1,arr);
          arr.pop_back();
          int first = solve(0,arr);
          return max(first,last);
          
      }
  };