// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int> (n));
        if(n * m != original.size()) return {};
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                ans[row][col] = original[row * n + col];
            }
        }
        return ans;
        
    }
};