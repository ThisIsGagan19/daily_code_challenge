// CODE

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int mx = 0, count = 0;
        int prev = arr[0];
        for(auto it: arr){
            if(it>prev){
                count++;
            }
            else{
                mx = max(count, mx);
                count = 0;
            }
            prev = it;
        }
        mx = max(count, mx);
        return mx;
    }
};