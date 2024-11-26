// CODE

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
// finding which team doesnt have indegree
        vector<bool> indegree(n, false);
// mark team true which is weaker than someone
        for(auto& edge : edges)
            indegree[edge[1]] = true;
// collecting all team which are not weaker than specific team
        vector<int> zeroIndegree;
        for(int i=0; i<n; i++)
            if(indegree[i] == false)
                zeroIndegree.push_back(i);
// if such teams are only one return it or else -1
        return (zeroIndegree.size() == 1) ? zeroIndegree[0] : -1;
    }
};