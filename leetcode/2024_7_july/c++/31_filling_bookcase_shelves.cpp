// TIME COMPLEXITY
// O(n*width)

// SPACE COMPLEXITY
// O(n*width)

// CODE

class Solution {
public:
    int width;
    int solve(vector<vector<int>>& books, int ind, int remainingW, int maxHeight, vector<vector<int> > &dp){
        if(ind >= books.size()) return maxHeight;

        if(dp[ind][remainingW] != -1) return dp[ind][remainingW];
        int bookW = books[ind][0];
        int bookH = books[ind][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(bookW <= remainingW){
            keep = solve(books,ind + 1,remainingW - bookW, max(maxHeight,bookH), dp);
        }

        skip = maxHeight + solve(books, ind + 1, width - bookW, bookH, dp);

        return dp[ind][remainingW] = min(keep,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int> > dp(n+1, vector<int>(shelfWidth+1, -1));
        width = shelfWidth;
        int remainingW = shelfWidth;
        return solve(books,0,remainingW,0,dp);
    }
};