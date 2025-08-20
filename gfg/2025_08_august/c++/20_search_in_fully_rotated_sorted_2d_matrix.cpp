// TC : O(log(N*M))
// SC : O(1)

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = n*m-1;
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            
            int lv = mat[l/m][l%m];
            int rv = mat[r/m][r%m];
            int mv = mat[mid/m][mid%m];
            
            if(mv == x) return true;
            
            if(lv <= mv){ // left side is sorted
                if(lv <= x && x < mv){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{ // right side is sorted
                if(mv < x && x <= rv){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};