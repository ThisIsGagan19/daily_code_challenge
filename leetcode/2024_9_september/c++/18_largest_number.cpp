// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    static bool cmp(int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        if(count(nums.begin(), nums.end(), 0) == nums.size()) return "0";
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for(auto it : nums){
            ans += to_string(it);
        }
        return ans;
    }
};