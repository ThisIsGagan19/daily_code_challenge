// TIME COMPLEXITY
// O(m * n)

// SPACE COMPLEXITY
// O(m * n)

// CODE

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        int new_row = i + row[k];
                        int new_col = j + col[k];
                        
                        if((new_row >=0 && new_col >= 0) && (new_row < n && new_col < m) 
                        && (matrix[new_row][new_col] == 1)){
                            cnt++;
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};