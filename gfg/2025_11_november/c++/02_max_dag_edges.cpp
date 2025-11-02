// CODE

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        // Topological sort (Kahn's algorithm)
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (!indegree[i]) q.push(i);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        // Build the set of existing edges for lookup
        unordered_set<long long> edgeSet;
        for (auto& edge : edges)
            edgeSet.insert((long long)edge[0] * V + edge[1]);
        
        int count = 0;
        // Try all pairs (i, j) where i comes before j in topo order
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                int u = topo[i], v = topo[j];
                if (edgeSet.find((long long)u * V + v) == edgeSet.end())
                    count++;
            }
        }
        return count;
    }
};