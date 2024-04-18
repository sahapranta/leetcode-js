// Approach 1 --> DFS
class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j, int perimeter) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++;
            return perimeter;
        }

        if (grid[i][j] == -1) {
            return perimeter;
        }

        grid[i][j] = -1;

        return dfs(grid, i + 1, j, perimeter) + dfs(grid, i - 1, j, perimeter) +
               dfs(grid, i, j + 1, perimeter) + dfs(grid, i, j - 1, perimeter);
    }    

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();    

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                  return dfs(grid, i, j, 0);
                }                
            }
        }
        return 0;
    }
};

// Approach 2 --> BFS
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int ii, int jj) {
        int perim = 0;

        queue<pair<int, int>> que;
        que.push({ii, jj});
        grid[ii][jj] = -1;

        while (!que.empty()) {
            auto it = que.front();
            que.pop();

            for (auto& dir : directions) {
                int i = it.first + dir[0];
                int j = it.second + dir[1];

                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                    perim++;
                } else if (grid[i][j] == -1) {
                    continue;
                } else {
                    que.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        return perim;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {                
                  return bfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};


// Approach 3 --> Normal Iteration

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int p = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {               
                if (grid[i][j] == 0)
                    continue;

                if (j + 1 >= n || grid[i][j + 1] == 0) {
                    p++;
                }

                if (j - 1 < 0 || grid[i][j - 1] == 0) {
                    p++;
                }

                if (i + 1 >= m || grid[i + 1][j] == 0) {
                    p++;
                }

                if (i - 1 < 0 || grid[i - 1][j] == 0) {
                    p++;
                }
            }
        }

        return p;
    }
};
