// TIME COMPLEXITY
// O(1)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
  
        int u1 = edges[0][0];
        int v1 = edges[0][1];
        int u2 = edges[1][0];
        int v2 = edges[1][1];
        
        // The center node will be the one that appears in both edges.
        if (u1 == u2 || u1 == v2) {
            return u1;
        } else {
            return v1;
        }
    }
};