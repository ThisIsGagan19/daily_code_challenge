// APPROACH : check the given condition properly and think of odd-even combination of making sum, {O+O = 0, E+E = 0}, {O+E = 1, E+O = 1}

// TC : O(N)
// SC : O(1)

// CODE

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int e = 0;
        int o = 0;
        int alt = 1;

        for(int &num : nums){
            if(num%2 == 0){
                e++;
            }
            else{
                o++;
            }
        }
        int parity = nums[0] % 2;
        for(int i = 1; i < n; i++){
            int currPar = nums[i] % 2;
            if(parity != currPar){
                alt++;
                parity = currPar;
            }
        }

        return max({e,o,alt});
    }
};