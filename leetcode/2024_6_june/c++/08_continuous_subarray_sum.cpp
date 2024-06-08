// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
                  //<rem , index>
        mp[0] = -1;
        int sum = 0;
        for(int i  = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k; // calculating remainder
            // map me check kro ki h yaa nhi
            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] >= 2) // check if size is greater or equal than 2
                    return true;
            }
            // nhi ha toh daalo yrr map me
            else{
                mp[rem] = i;
            }
        }
        return false;
    }
};