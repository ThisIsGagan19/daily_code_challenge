// CODE

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<n-1;i++){
            g[i].emplace_back(i+1,1);
        }
        auto dijkstra = [&](int s,int t)-> int{
            vector<int> dis(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.emplace(0,s);
            dis[s]=0;
            while(!pq.empty()){
                auto [d,u] =pq.top();
                pq.pop();
                if(d>dis[u]) continue;
                for(auto [v,w] : g[u]){
                    if(dis[u]+w<dis[v]){
                        dis[v]=dis[u]+w;
                        pq.emplace(dis[v],v);
                    }
                }
            }
            return dis[t];

        };
        vector<int> a;
        for(auto q: queries){
            int u=q[0];
            int v=q[1];
            g[u].emplace_back(v,1);
            a.push_back(dijkstra(0,n-1));
        }
        return a;
    }
};