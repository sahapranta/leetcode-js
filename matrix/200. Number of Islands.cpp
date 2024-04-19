class Solution {
public:
    int m;
    int n;

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = 'x';

        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        return;
    }

    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int ii, int jj) {
        queue<pair<int, int>> que;
        que.push({ii, jj});
        grid[ii][jj] = 'x';

        while (!que.empty()) {
            auto it = que.front();

            que.pop();

            for (auto& d : dir) {
                int i = it.first + d[0];
                int j = it.second + d[1];

                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                    continue;
                } else {
                    que.push({i, j});
                    grid[i][j] = 'x';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    // dfs(grid, i, j);
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};
