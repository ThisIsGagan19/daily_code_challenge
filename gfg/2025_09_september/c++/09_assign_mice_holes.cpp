// TC = O(NlogN)
// SC = O(1)

// CODE

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int i = 0;
        int maxi = INT_MIN;
        while(i < mices.size()){
            int diff = abs(mices[i] - holes[i]);
            maxi = max(maxi,diff);
            i++;
        }
        return maxi;
    }
};