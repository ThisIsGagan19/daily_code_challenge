// TIME COMPEXITY
// O(n^2)

// SPACE COMPEXITY
// O(n^2)

// CODE

class Solution {
public:
    void dfs(int row , int col , int size ,  vector<vector<int>>&matrix ){
        if(row < 0 || col < 0 || row >= size || col >= size || matrix[row][col] == 1)
        return ;

        matrix[row][col] = 1 ;

        dfs(row+1 , col , size , matrix) ; 
        dfs(row-1 , col , size , matrix) ;
        dfs(row , col+1 , size , matrix) ;
        dfs(row ,col-1 , size , matrix) ;
    }
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size() ; 
        int cols = grid[0].size() ; 
        cout<<cols<<endl ;

        vector<vector<int>>matrix(rows*3 , vector<int>(cols*3 , 0));
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3+2][j*3] = 1 ;
                    matrix[i*3+1][j*3+1] = 1 ;
                    matrix[i*3][j*3+2] = 1 ;
                }
                else if( grid[i][j] != ' '){
                    matrix[i*3][j*3] = 1 ;
                    matrix[i*3+1][j*3+1] = 1 ;
                    matrix[i*3+2][j*3+2] = 1 ;
                    
                }
            }
        }
        int count = 0  ;
        for(int i = 0 ; i < rows*3 ; i++){
            for(int j = 0 ; j < cols*3 ; j++){
                if(matrix[i][j] == 0){
                    dfs( i , j , cols*3 , matrix ) ;
                    count++ ;
                }
            }
        }
        return count ; 
    }
};