// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];

            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};