// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n * m)

// CODE

class Solution {
public:
    bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size()){
            return true;
        }
        if(grid2[i][j] != 1) return true;
        grid2[i][j] = -1; // visit ho gya h

        bool res = (grid1[i][j] == 1);

        // aage badho down up right left
        res = res & check(grid1,grid2,i+1,j);
        res = res & check(grid1,grid2,i-1,j);
        res = res & check(grid1,grid2,i,j+1);
        res = res & check(grid1,grid2,i,j-1);
        
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && check(grid1,grid2,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};