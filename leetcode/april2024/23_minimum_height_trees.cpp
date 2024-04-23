// CODE

class Solution {
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0), res;

        // creating adjacency matrix
        for(auto &e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        // adding leaf nodes into queue
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 1) q.push(i), indegree[i]--;
        
        while(!q.empty()) {
            int s = q.size();
            res.clear();
            for(int i = 0; i < s; i++) {
                int curr = q.front(); q.pop();
                res.push_back(curr);
                for(auto nbr : adjList[curr]) {
                    indegree[nbr]--;
                    if(indegree[nbr] == 1) q.push(nbr);
                }
            }
        }

        return res;
    }
};