// TC : O(N)
// SC : O(1)

// CODE

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxDiag = 0;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int len = dimensions[i][0];
            int bre = dimensions[i][1];

            int diag = (len*len) + (bre*bre);
            int area = len * bre;
            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }
            else if(diag == maxDiag){
                maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};