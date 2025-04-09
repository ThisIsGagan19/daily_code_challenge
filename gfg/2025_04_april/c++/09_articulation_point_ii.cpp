// CODE

class Solution {
    private:
    int timer = 0;
    void dfs(int node, int par, vector<int> & vis, int tin[], int low[], vector<int> & mark, vector<vector<int>> & adj){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == par) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && par != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
        if(child > 1 && par == -1){
            mark[node] = 1;
        }
    }
    public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};