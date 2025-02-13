// TC : O(n * k)  k -> no. of digits in each number
// SC : O(82) -> constant

// CODE

class Solution {
public:
    int solve(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int arr[82];
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            int digitSum = solve(nums[i]);
            if(arr[digitSum] > 0){
                ans = max(ans,arr[digitSum] + nums[i]);
            }
            arr[digitSum] = max(nums[i],arr[digitSum]);
        }
        return ans;
    }
};