// CODE

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(maxi < sum) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};