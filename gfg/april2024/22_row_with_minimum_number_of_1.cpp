// CODE

class Solution {
    public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int cnt, res = 0;
        int max1 = m;
        for(int i = 0; i < n; i++) {
            cnt = 0;
            for(int j = 0; j < m; j++)
                if(a[i][j] == 1) cnt++;
            if(cnt < max1) {
                max1 = cnt;
                res = i;
            }
        }
        return res + 1;
    }
};