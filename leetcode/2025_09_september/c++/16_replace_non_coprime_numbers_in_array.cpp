// TC = O(NlogX) where X is the min element in the prev and curr
// SC = O(1)

// CODE

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            while(!res.empty()){
                int prev = res.back();
                int curr = num;
                int g = gcd(prev,curr);
                if(g == 1) break;
                res.pop_back();
                int lcm = prev/g * curr;
                num = lcm;
            }
            res.push_back(num);
        }
        return res;
    }
};