// THINKING & LEARNING
// if components occurs then think of DSU.
// if we doing AND(&) - operation continously then answer will never increase, it goes on decreasing and decreasing.

// CODE

class Solution {
    public:
        // assign parent vector
        vector<int> papa;
        // use DSU
        int find(int x){
            if(papa[x] == x) return x;
            return papa[x] = find(papa[x]);
        }
        void Union(int x, int y){
            papa[y] = x;
        }
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            papa.resize(n);
            // assign cost vector
            vector<int>cost(n);
            // assign parent to i and cost to -1
            for(int i = 0; i < n; i++){
                papa[i] = i;
                cost[i] = -1;
            }
    
            // process each edge
            for(auto &e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
    
                int papa_u = find(u);
                int papa_v = find(v);
    
                if(papa_u != papa_v){
                    Union(papa_u, papa_v);
                    cost[papa_u] &= cost[papa_v];
                }
                cost[papa_u] &= w;
            }
    
            // process query
            vector<int> ans;
            for(auto &q : query){
                int s = q[0];
                int t = q[1];
    
                int papa_s = find(s);
                int papa_t = find(t);
    
                if(s == t) ans.push_back(0);
                else if(papa_s != papa_t) ans.push_back(-1);
                else{
                    ans.push_back(cost[papa_s]);
                }
            }
    
            return ans;
        }
    };