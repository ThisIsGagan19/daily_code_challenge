// INTUITION
// Standard DP Question, Just have to move down and right

// CODE

class Solution {
	public:
	int solve(vector<vector<int>> &points, int &m, int &n, int i, int j, vector<vector<int>> &cache) {
	    if(i >= m or j >= n) return INT_MAX;
	    if(i == m - 1 and j == n - 1) return 1 - points[i][j];
	    if(cache[i][j] != -1) return cache[i][j];
	    int down = solve(points, m, n, i + 1, j, cache);
	    int right = solve(points, m, n, i, j + 1, cache);
	    return cache[i][j] = max(1, min(down, right) - points[i][j]);
	}
	int minPoints(int m, int n, vector<vector<int>> points) {
	    vector<vector<int>> cache(m, vector<int>(n, -1));
	    return solve(points, m, n, 0, 0, cache);
	} 
};