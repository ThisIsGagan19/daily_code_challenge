// INTUITION
// Alright!! consider some points
// 1. Number can only be in range 1 to N + 1, in every case.
// 2. If negative number comes, number > N comes or any number 
//    repeates then our range decreases to 1 to N.
// 3. So, we just have to arrange numbers with in range of 1 to N,
//    in order inside array to obtain our result.
// 4. We will move numbers in range 1 to N to their correct position
//    like N = 10, then 5 to index 4, 1 to index 0 and so on..
// 5. Finally, we will traverse and if we found any outlier while
//    traversing then (i + 1) will be our result.

// If have some issues in understanding use pen and paper to dry run 
// and try to understand all 5 points mentioned above.

// TIME COMPLEXITY
// TC: O(n)

// SPACE COMPLEXITY
// SC: O(1)

// CODE

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(i = 0; i < n; i++) {
            if(i + 1 != nums[i]) return i + 1;
        }
        return n + 1;
    }
};