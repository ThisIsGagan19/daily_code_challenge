// TC : O(N*M)
// SC : O(N*M)

// CODE

class Solution {
public:
    vector<vector<int>> dir = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int t[501][501][4][2];
    int solve(int i, int j, int d, bool turn, vector<vector<int>>& grid, int val){
        int n = grid.size();
        int m = grid[0].size();
        int new_i = i + dir[d][0];
        int new_j = j + dir[d][1];

        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || grid[new_i][new_j] != val){
            return 0;
        }

        if(t[new_i][new_j][d][turn] != -1){
            return t[new_i][new_j][d][turn];
        }

        int len = 0;

        int keepMoving = 1 + solve(new_i,new_j,d,turn,grid,(val == 2)? 0 : 2);
        len = max(len,keepMoving);

        if(turn == true){
            int turnNMove = max(1 + solve(new_i,new_j,(d+1)%4,false,grid,(val == 2)? 0 : 2),keepMoving);
            len = max(len,turnNMove);
        }
        return t[new_i][new_j][d][turn] = len;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(t,-1,sizeof(t));

        int res = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d <= 3; d++){
                        res = max(res, 1 + solve(i,j,d,true,grid,2));
                    }
                }
            }
        }
        return res;
    }
};