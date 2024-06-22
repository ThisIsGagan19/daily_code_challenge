// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n       = nums.size();
        int count   = 0;
        int currSum = 0;
        mp[currSum] = 1;

        for(int i = 0; i < n; i++) {
            currSum += (nums[i]%2); //if odd - 1, even - 0

            if(mp.count(currSum - k)) {
                count += mp[currSum-k];
            }

            mp[currSum]++;
        }

        return count;

    }
};