// INTUITION
// Another player will try to maximize his score, but take it like he will try to 
// minimize your score. So, he will choose the path which will give you minimum
// score.

// TIME COMPLEXITY
// O(n * n)

// SPACE COMPLEXITY
// O(n * n)

// CODE

class Solution{
    public:
    long long solve(int i, int j, int arr[], vector<vector<long long>> &cache){
        if(j < i) return 0;
        if(cache[i][j] != -1) return cache[i][j];
        long long takeLeft, takeRight;
        takeLeft = arr[i] + min(solve(i + 2, j, arr, cache), solve(i + 1, j - 1, arr, cache));
        takeRight = arr[j] + min(solve(i + 1, j - 1, arr, cache), solve(i, j - 2, arr, cache));
        return cache[i][j] = max(takeLeft, takeRight);
    }
    
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> cache(n, vector<long long>(n, -1));
        return solve(0, n - 1, arr, cache);
    }
};