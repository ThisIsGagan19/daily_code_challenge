// CODE

class Solution {
	public:
	int solve(int* a, int* b, int i, int j, vector<vector<int>>& cache) {
	    if(j < 0) return 0;
	    if(i < 0) return -1e9;
	    if(cache[i][j] != -1) return cache[i][j];
	    int nottake = solve(a, b, i - 1, j, cache);
	    int take = a[i] * b[j] + solve(a, b, i - 1, j - 1, cache);
	    return cache[i][j] = max(take, nottake);
	}
	
	int maxDotProduct(int n, int m, int a[], int b[]) { 
	    vector<vector<int>> cache(n, vector<int>(m, -1));
		int res = solve(a, b, n - 1, m - 1, cache);
		return res;
	} 
};