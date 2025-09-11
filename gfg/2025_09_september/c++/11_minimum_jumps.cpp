// TC = O(N)
// SC = O(1)

// CODE

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if(arr[0] == 0) return -1;
        int n = arr.size();
        int jumps = arr[0];
        int ans = 1;
        int maxi = 0;
        for(int i = 1; i < n; i++){
            jumps--;
            maxi--;
            maxi = max(maxi,arr[i]);
            if(jumps <= 0 && i < n-1){
                if(maxi <= 0) return -1;
                ans++;
                jumps = maxi;
                maxi = 0;
            }
        }
        return ans;
    }
};
