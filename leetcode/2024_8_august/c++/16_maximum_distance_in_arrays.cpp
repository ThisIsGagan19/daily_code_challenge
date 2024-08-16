// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int miniboi = arrays[0].front();
        int maxiboi = arrays[0].back();

        int res = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            res = max({res, abs(currMin - maxiboi), abs(currMax - miniboi)});

            miniboi = min(miniboi, currMin);
            maxiboi = max(maxiboi, currMax);
        }
        return res;
    }
};