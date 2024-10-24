// CODE

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        int k = 0;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] == arr[i+1] && arr[i] != 0){
                ans[k] = 2 * arr[i];
                k++;
                i++;
            }
            else if(arr[i] != 0){
                ans[k] = arr[i];
                k++;
            }
        }
        ans[k] = arr[n-1];
        return ans;
    }
};