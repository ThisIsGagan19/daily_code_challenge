// CODE

class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          vector<int> dist(V,1e9);
          vector<vector<pair<int,int>>> adj(V);
          
          for(auto it : edges){
              int u = it[0];
              int v = it[1];
              int w = it[2];
              
              adj[u].push_back({v,w});
              adj[v].push_back({u,w});
          }
          dist[src] = 0;
          pq.push({0,src});
          
          while(!pq.empty()){
              int d = pq.top().first;
              int node = pq.top().second;
              pq.pop();
              
              for(auto it : adj[node]){
                  int wei = it.second;
                  int adjNode = it.first;
                  if(d+wei < dist[adjNode]){
                      dist[adjNode] = d + wei;
                      pq.push({dist[adjNode], adjNode});
                  }
              }
          }
          return dist;
      }
};
