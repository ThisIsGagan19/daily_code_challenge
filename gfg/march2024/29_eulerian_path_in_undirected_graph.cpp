// INTUITION
// A path is eulerian path if every vertex has even degree

// CODE

class Solution {
    public:
	bool isEularCircuitExist(int v, vector<int>adj[]) {
	    for(int i = 0; i < v; i++)
	        if(adj[i].size() & 1) return 0;
	    return 1;
	}

};