// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        long long n = arr.size();
        long long sum = 0;
        long long maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};