// INTUITION
// Kadane's algorithm variation

// APPROACH
// Check out Kadane's algorithm

// TIME COMPLEXITY
// TC: O(n)

// SPACE COMPLEXITY
// SC: O(n) - for hashmap

// CODE

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> index;
        index[0] = -1;
        int cnt = 0, len = 0;
        for(int i = 0; i < n; i++) {
            cnt = cnt + (nums[i] == 1 ? 1 : -1);
            if(index.find(cnt) != index.end()) {
                len = max(len, i - index[cnt]);
            } else {
                index[cnt] = i;
            }
        }
        return len;
    }
};