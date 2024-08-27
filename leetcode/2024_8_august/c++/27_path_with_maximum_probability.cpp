// TIME COMPEXITY
// O(elogv)

// SPACE COMPEXITY
// O(e+v)

// CODE

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double> > > adj;
        vector<double> res(n,0);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<pair<double,int> > pq;
        res[start_node] = 1;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();
            for(auto &node : adj[currNode]){
                if(res[node.first] < currProb * node.second){
                    res[node.first] = currProb * node.second;
                    pq.push({res[node.first],node.first});
                }
            }
        }
        return res[end_node];
    }
};