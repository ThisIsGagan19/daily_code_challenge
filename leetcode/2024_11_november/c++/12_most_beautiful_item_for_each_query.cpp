// CODE

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
    int n = queries.size();
    int m = items.size();
    sort(items.begin(), items.end());

    // Precompute the maximum values up to each index in items
    vector<int> maxVal(m);
    maxVal[0] = items[0][1];
    for (int i = 1; i < m; i++) {
        maxVal[i] = max(maxVal[i - 1], items[i][1]);
    }

    // Process each query
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int q = queries[i];
        
        // Binary search to find the largest j where items[j][0] <= q
        int l = 0, r = m - 1, pos = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (items[mid][0] <= q) {
                pos = mid; // Update the position
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        // If pos is found, set ans[i] to maxVal[pos]
        if (pos != -1) {
            ans[i] = maxVal[pos];
        }
    }

    return ans;
    }
};