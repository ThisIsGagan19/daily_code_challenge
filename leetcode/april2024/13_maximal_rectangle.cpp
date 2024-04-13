// CODE

class Solution {
    public:
    int largestRectangleArea(vector<int> &histogram) {
        stack<int> s;
        int area = 0, n = histogram.size();
        for(int i = 0; i <= n; i++) {
            while(!s.empty() and (i == n or histogram[s.top()] >= histogram[i])) {
                int w, h = histogram[s.top()];
                s.pop();
                if(s.empty()) w = i;
                else w = i - s.top() - 1;
                area = max(area, h * w);
            }
            s.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> prefixHeight(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') prefixHeight[j]++;
                else prefixHeight[j] = 0;
            }
            int area = largestRectangleArea(prefixHeight);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};