// TC : O(N^2)
// SC : O(1)

// CODE

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        for(int i = n-1; i >= 2; i--){
            int j = 0;
            int k = i - 1;
            while(j < k){
                int sum2side = arr[j] + arr[k];
                if(sum2side > arr[i]){
                    ans += k-j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};