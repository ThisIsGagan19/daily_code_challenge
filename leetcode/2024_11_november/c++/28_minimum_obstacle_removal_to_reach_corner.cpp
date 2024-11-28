// CODE

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        deque<pair<int, int>> dq;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        dis[0][0] = 0;
        dq.push_front({ 0, 0 });

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto [dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == INT_MAX) {
                    int newDis = dis[x][y] + (grid[nx][ny] == 1 ? 1 : 0);
                    if (newDis < dis[nx][ny]) {
                        dis[nx][ny] = newDis;
                        if (grid[nx][ny]) {
                            dq.push_back({ nx, ny });
                        } else {
                            dq.push_front({ nx, ny });
                        }
                    }
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};