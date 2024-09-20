// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int ans = 1;
        int maxi = height[0];
        for(int i = 1; i < height.size(); i++){
            if(height[i] > maxi){
                maxi = height[i];
                ans++;
            }
        }
        return ans;
    }
};