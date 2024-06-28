// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>m(n,0);
        for(auto vec : roads) {
            int u = vec[0];
            int v = vec[1];
            m[u]++;
            m[v]++;
        }
        sort(begin(m),end(m));
        long long value= 1;
        long long result = 0 ;
      for(int i=0 ; i<n ; i++) {
        result += (m[i]*value);
        value++ ;
      }
        return result ;
    }
};