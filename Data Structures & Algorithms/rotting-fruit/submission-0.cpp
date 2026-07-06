class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and push rotten ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            int nc = q.size();
            bool changed = false;

            while (nc--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    if (grid[nx][ny] != 1)
                        continue;

                    // Rot the fresh orange
                    grid[nx][ny] = 2;
                    fresh--;
                    changed = true;

                    q.push({nx, ny});
                }
            }

            if (changed)
                minutes++;
        }

        if (fresh > 0)
            return -1;

        return minutes;
    }
};