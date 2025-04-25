// CODE

class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          int ans = 0;
          int cnt = 0;
          for(int i = 0; i < arr.size(); i++){
              if(cnt == 0){
                  cnt = 1;
                  ans = arr[i];
              }
              else if(arr[i] == ans) cnt++;
              else cnt--;
          }
          
          cnt = 0;
          for(int i = 0; i < arr.size(); i++){
              if(arr[i] == ans) cnt++;
          }
          if(cnt > arr.size() / 2) return ans;
          return -1;
          
      }
};