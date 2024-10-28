// CODE

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int hash[100001] = {0};
        
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int temp = 0;
            
            while (current <= 100000 && hash[current] > 0) {
                temp++;
                hash[current]--;
                
                long long nextSquare = (long long)current * current;
                if (nextSquare > 100000) break;
                
                current = nextSquare;
            }
            
            cnt = max(cnt, temp);
        }
        
        return (cnt > 1 ? cnt : -1);
    }
};