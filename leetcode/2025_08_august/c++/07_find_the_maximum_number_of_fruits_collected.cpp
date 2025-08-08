// TC : O(N^2)
// SC : O(N^2)

// CODE

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int c1(vector<vector<int>>& fruits){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += fruits[i][i];
            fruits[i][i] = 0;
        }
        return cnt;
    }

    int c2(int i, int j, vector<vector<int>>& fruits){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i == n-1 && j == n-1) return 0;
        if(i == j || i > j) return 0; // child 2 goes out of range

        if(dp[i][j] != -1) return dp[i][j];

        int m1 = fruits[i][j] + c2(i+1,j-1,fruits);
        int m2 = fruits[i][j] + c2(i+1,j,fruits);
        int m3 = fruits[i][j] + c2(i+1,j+1,fruits);

        return dp[i][j] = max({m1,m2,m3});
    }

    int c3(int i, int j, vector<vector<int>>& fruits){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i == n-1 && j == n-1) return 0;
        if(i == j || i < j) return 0; // child 3 goes out of range

        if(dp[i][j] != -1) return dp[i][j];

        int m1 = fruits[i][j] + c3(i-1,j+1,fruits);
        int m2 = fruits[i][j] + c3(i,j+1,fruits);
        int m3 = fruits[i][j] + c3(i+1,j+1,fruits);

        return dp[i][j] = max({m1,m2,m3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp.resize(n,vector<int>(n,-1));
        // int child1 = c1(fruits);
        // int child2 = c2(0,n-1,fruits);
        // int child3 = c3(n-1,0,fruits);

        // return child1+child2+child3;

        // tabulation approach
        
        // for child 1
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += fruits[i][i];
            fruits[i][i] = 0;
        }

        // mark 0 those places which we cant access for c2 and c3
        for(int i = 0; i < n; i++){
            for(int j= 0; j < n; j++){
                if(i < j && i+j < n-1){
                    dp[i][j] = 0;
                }
                else if(i > j && i+j < n-1){
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = fruits[i][j];
                }
            }
        }

        // collect fruits for child 2
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp[i][j] += max({dp[i-1][j-1], dp[i-1][j], (j+1 < n)? dp[i-1][j+1] : 0});
            }
        }

        // collect fruits for child 3
        for(int j = 1; j < n; j++){
            for(int i = j+1; i < n; i++){
                dp[i][j] += max({dp[i-1][j-1], dp[i][j-1], (i+1 < n)? dp[i+1][j-1] : 0});
            }
        }

        return cnt + dp[n-2][n-1] + dp[n-1][n-2];
    }
};

