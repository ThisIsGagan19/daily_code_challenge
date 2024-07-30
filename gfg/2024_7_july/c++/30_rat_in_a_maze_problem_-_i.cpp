// TIME COMPLEXITY
// O(exponential)

// SPACE COMPLEXITY
// O(n^2)

// CODE

class Solution {
  public:
    bool isSafe(int new_x, int new_y, vector<vector<bool>> &vis, vector<vector<int>> & arr, int n)
    {
        if((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n) && vis[new_x][new_y] != 1 && arr[new_x][new_y] == 1){
            return true;
        }
        return false;
    }
    void solve(int x, int y, string path, vector<string> &ans, 
                vector<vector<bool>> &vis, vector<vector<int>> & arr, int n)
    {
        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return ;
        }
        vis[x][y] = 1;
        // movemnets -> D L R U
        // down
        if(isSafe(x+1,y,vis,arr,n)){
            
            solve(x+1,y,path+'D',ans,vis,arr,n);
            
        }
        // left
        if(isSafe(x,y-1,vis,arr,n)){
    
            solve(x,y-1,path+'L',ans,vis,arr,n);
            
        }
        // right
        if(isSafe(x,y+1,vis,arr,n)){
    
            solve(x,y+1,path+'R',ans,vis,arr,n);
    
        }
        // up
        if(isSafe(x-1,y,vis,arr,n)){
    
            solve(x-1,y,path+'U',ans,vis,arr,n);
    
        }
    
        vis[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n,0));
        string path = "";
    
        if(arr[0][0] == 0){
            return ans;
        }
    
        solve(0,0,path,ans,vis,arr,n);
        return ans;
    }
};