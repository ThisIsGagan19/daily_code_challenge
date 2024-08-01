// TIME COMPEXITY
// O(row*col)

// SPACE COMPEXITY
// O(row*col)

// CODE

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int stRow = 0;
        int stCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        
        int cnt = 0;
        int total = row * col;
        
        while(cnt < total){
            // starting row
            for(int i = stCol; cnt < total && i <= endCol; i++){
                ans.push_back(matrix[stRow][i]);
                cnt++;
            }
            stRow++;
            
            // ending col
            for(int i = stRow; cnt < total && i <= endRow; i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;
            // ending row
            for(int i = endCol; cnt < total && i >= stCol; i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;
            // starting col
            for(int i = endRow; cnt < total && i >= stRow; i--){
                ans.push_back(matrix[i][stCol]);
                cnt++;
            }
            stCol++;
        }
        
        return ans;
    }
};