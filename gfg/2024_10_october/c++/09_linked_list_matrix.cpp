// CODE

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<Node*> > ans(n,vector<Node*> (m, NULL));
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                ans[i][j] = new Node(mat[i][j]);
                if(i + 1 < n){
                    ans[i][j] -> down = ans[i+1][j];
                }
                if(j + 1 < m){
                    ans[i][j] -> right = ans[i][j+1];
                }
            }
        }
        
        return ans[0][0];
    }
};