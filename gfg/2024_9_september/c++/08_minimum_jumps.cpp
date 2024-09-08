// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if(arr[0] == 0) return -1;
        int ans = 1;
        int jumps = arr[0];
        int maxi = 0;
        for(int i = 1; i < arr.size(); i++){
            maxi--;
            jumps--;
            maxi = max(maxi, arr[i]);
            if(jumps <= 0 && i < arr.size() - 1){
                if(maxi <= 0) return -1;
                jumps = maxi;
                maxi = 0;
                ans++;
            }
        }
        return ans;
    }
};