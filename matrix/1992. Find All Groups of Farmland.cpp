class Solution {

public:
    int m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& land, int ii, int jj, int& r2, int& c2) {
        land[ii][jj] = 0;

        r2 = max(r2, ii);
        c2 = max(c2, jj);

        for (auto& dir : directions) {
            int i = ii + dir[0];
            int j = jj + dir[1];
            if (i >= 0 && i < m && j >= 0 && j < n && land[i][j] == 1) {
                dfs(land, i, j, r2, c2);
            }
        }
    }

    void bfs(vector<vector<int>>& land, int ii, int jj, int& r2, int& c2) {
        queue<pair<int, int>> que;
        que.push({ii, jj});

        while (!que.empty()) {
            pair<int, int> p = que.front();
            que.pop();

            r2 = max(r2, p.first);
            c2 = max(c2, p.second);

            for (auto& dir : directions) {
                int i = p.first + dir[0];
                int j = p.second + dir[1];
                if (i >= 0 && i < m && j >= 0 && j < n && land[i][j] == 1) {
                    land[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        return findFarm(land);

        vector<vector<int>> result;
        m = land.size();
        n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r2 = -1;
                    int c2 = -1;

                    bfs(land, i, j, r2, c2);
                    // dfs(land, i, j, r2, c2);
                    result.push_back({i, j, r2, c2});
                }
            }
        }

        return result;
    }

    vector<vector<int>> findFarm(vector<vector<int>>& land) {
        vector<vector<int>> result;
        m = land.size();
        n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0)
                    continue;

                // find the right most column
                int c1 = j;
                while (c1 < n && land[i][c1] == 1) {
                    c1++;
                }

                // find the bottom most row
                int r1 = i;
                while (r1 < m && land[r1][j] == 1) {
                    r1++;
                }

                if (c1 != 0) {
                    c1--;
                }

                if (r1 != 0) {
                    r1--;
                }

                result.push_back({i, j, r1, c1});

                for (int k = i; k <= r1; k++) {
                    for (int l = j; l <= c1; l++) {
                        land[k][l] = 0;
                    }
                }
            }
        }

        return result;
    }
};
