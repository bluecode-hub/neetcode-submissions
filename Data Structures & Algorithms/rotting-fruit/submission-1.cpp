class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and push all rotten oranges
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if (fresh == 0)
            return 0;

        int dirx[4] = {1, -1, 0, 0};
        int diry[4] = {0, 0, 1, -1};

        int time = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool rotten = false;

            while (sz--) {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dirx[i];
                    int ny = y + diry[i];

                    if (nx < 0 || ny < 0 || nx >= row || ny >= col)
                        continue;

                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;      // Rot it
                        fresh--;               // One less fresh orange
                        q.push({nx, ny});      // It will rot others next minute
                        rotten = true;
                    }
                }
            }

            // One minute passes only if at least one orange rotted
            if (rotten)
                time++;
        }

        return (fresh == 0) ? time : -1;
    }
};