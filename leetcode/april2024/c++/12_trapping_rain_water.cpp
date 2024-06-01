// CODE

class Solution {
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        long long lMax[n], rMax[n];
        long long res = 0;
        
        lMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            lMax[i] = max(lMax[i - 1], (long long)height[i]);
        }
        
        rMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rMax[i] = max(rMax[i + 1], (long long)height[i]);
        }
        
        for(int i = 0; i < n; i++) {
            int waterHeight = min(lMax[i], rMax[i]);
            res += ((waterHeight > height[i]) ? waterHeight - height[i] : 0);
        }
        
        return res;
    }
};