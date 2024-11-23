// CODE

class Solution {
  public:
    int getMinDiff(int k, vector<int>& arr) {
        // Step 1: Sort the array to ensure heights are ordered
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        // Initial maximum difference between the tallest and shortest tower
        int ans = arr[n-1] - arr[0];
        
        int mi, ma; // Variables to store the current minimum and maximum
        
        // Step 2: Iterate through the array to calculate possible differences
        for (int i = 1; i < n; i++) {
            // Maximum height can either be reduced by k (last tower) 
            // or increased by k (current tower after modification)
            ma = max(arr[n-1] - k, arr[i-1] + k);
            
            // Minimum height can either be increased by k (first tower) 
            // or reduced by k (current tower after modification)
            mi = min(arr[0] + k, arr[i] - k);
            
            // Step 3: Update the minimum difference found so far
            ans = min(ans, ma - mi);
        }
        
        // Step 4: Return the minimum difference
        return ans;
    }
};