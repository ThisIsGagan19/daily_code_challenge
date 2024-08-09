// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> s;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int num = grid[r+i][c+j];
                if(num < 1 | num > 9 || s.count(num)) return false;
                else s.insert(num);
            }
        }

        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        for(int i = 0; i < 3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
        }

        // diagonal aur anti dia
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i <= n-3; i++){
            for(int j = 0; j <= m-3; j++){
                if(check(grid,i,j)) cnt++;
            }
        }
        return cnt;
    }
};