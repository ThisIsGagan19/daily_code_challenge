// CODE

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(m, vector<int> (n,0));
        for(int i=0; i< w.size(); i++) {
            v[ w[i][0] ][ w[i][1] ] = 2;
        }

        for(int i=0; i< g.size(); i++) {
            v[ g[i][0] ][ g[i][1] ] = 2;
        }

        for(int i=0; i< g.size(); i++) {
            int x= g[i][0], y= g[i][1];
            v[ x ][ y ] = 2;
            while( x+1 < m && v[x+1][y]<2){
                v[x+1][y] =1;
                x++;
            }
            x= g[i][0];
            while( x-1 >=0 && v[x-1][y]<2) {
                v[x-1][y] =1;
                x--;
            }
            x= g[i][0];
            while( y+1 < n && v[x][y+1]<2 ) {
                v[x][y+1] =1;
                y++;
            }
            y = g[i][1];
            while( y-1 >=0 && v[x][y-1]<2) {
                v[x][y-1] =1;
                y--;
            }
        }
        
        int cnt =0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j] == 0) cnt ++; 
            }
        }
        return cnt;
    }
};