// CODE

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (const auto& e : edges)
            adj[e[0]].push_back(e[1]);
        
        // Reverse graph
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        // Nodes with 0 out-degree in original: terminal nodes
        for (int i = 0; i < V; ++i)
            if (indegree[i] == 0) q.push(i);
        
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (int parent : revAdj[node]) {
                indegree[parent]--;
                if (indegree[parent] == 0)
                    q.push(parent);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};