// 1. sort the vector of {u,v,w} acc. to weight 
// 2. apply kruskal using DSU

// CODE

class Solution {
    public:
      //DSU Code
      vector<int> parent;
      vector<int> rank;
      
      int find (int x) {
          if (x == parent[x]) 
              return x;
      
          return parent[x] = find(parent[x]);
      }
      
      void Union (int x, int y) {
          int x_parent = find(x);
          int y_parent = find(y);
      
          if (x_parent == y_parent) 
              return;
      
          if(rank[x_parent] > rank[y_parent]) {
              parent[y_parent] = x_parent;
          } else if(rank[x_parent] < rank[y_parent]) {
              parent[x_parent] = y_parent;
          } else {
              parent[x_parent] = y_parent;
              rank[y_parent]++;
          }
      }
      
      int kruskal(vector<vector<int>>& adj){
          int sum = 0;
          for(auto it : adj){
              int u = it[0];
              int v = it[1];
              int w = it[2];
              
              int p_u = find(u);
              int p_v = find(v);
              if(p_u != p_v){
                  Union(u,v);
                  sum += w;
              }
          }
          return sum;
      }
      int minCost(vector<vector<int>>& h) {
          int n = h.size();
          parent.resize(n);
          rank.resize(n,0);
          for(int i = 0; i < n; i++){
              parent[i] = i;
          }
          
          vector<vector<int>> adj;
          for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){
                  int x1 = h[i][0];
                  int y1 = h[i][1];
                  
                  int x2 = h[j][0];
                  int y2 = h[j][1];
                  
                  int d = abs(x1-x2) + abs(y1-y2);
                  
                  adj.push_back({i,j,d});
              }
          }
          
          auto comparator = [&](vector<int>& v1, vector<int>& v2){
              return v1[2] < v2[2];
          };
          sort(adj.begin(), adj.end(), comparator);
          
          return kruskal(adj);
          
      }
  };