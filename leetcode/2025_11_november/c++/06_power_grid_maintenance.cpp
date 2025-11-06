//CODE

constexpr int N=1e5+1;
int root[N], Rank[N];
class UnionFind {
public:
    UnionFind(int n){
        fill(Rank, Rank+(n+1), 1);
        iota(root, root+(n+1), 0);
    }

    int Find(int x) { // Path compression
        return (x==root[x])?x:root[x]=Find(root[x]);
    }

    bool Union(int x, int y) { // Union by rank
        x=Find(x), y=Find(y);
        if (x == y)
            return 0;
        if (Rank[x] > Rank[y])
            swap(x, y);
        root[x]=y;
        if (Rank[x]==Rank[y])
            Rank[y]++;
        return 1;
    }
};

class Solution {
public:
    static vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind G(c);
        for (auto& e : connections) 
            G.Union(e[0], e[1]);

        vector<int> cntOff(c+1, 0), minOn(c+1, -1);
        int sz=0;

        for (auto& q : queries) {
            const int t=q[0], x=q[1];
            if (t==2) cntOff[x]++;
            else sz++;
        }

        vector<int> ans(sz);

        // compute initial minOn per component
        for (int i=1; i<=c; i++) {
            if (cntOff[i]==0) {
                int rx=G.Find(i);
                if (minOn[rx]==-1 || minOn[rx]>i)
                    minOn[rx]=i;
            }
        }

        for (int i=queries.size()-1, j=sz-1; i>=0; i--) {
            const int t=queries[i][0], x=queries[i][1], rx=G.Find(x);
            int minS=minOn[rx];

            if (t==1) 
                ans[j--]=(cntOff[x]==0 ? x : minS);
            else {
                cntOff[x]--;
                if (cntOff[x]==0) {
                    if (minOn[rx]==-1 || minOn[rx]>x)
                        minOn[rx]=x;
                }
            }
        }
        return ans;
    }
};