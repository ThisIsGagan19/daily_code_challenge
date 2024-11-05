// CODE

void rotate(vector<vector<int> >& mat) {
    int n = mat.size();
    for(int i = 0 ;i<n;i++){
        for(int j = i;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
        reverse(mat[i].begin(),mat[i].end());
    }
}