class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int target = grid[row][col];
        solve(grid, visited, row, col, target, color);

        // Recolor only marked border cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 100) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }

    void solve(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int target, int color) {
        int m = grid.size(), n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n) return;  // out of bounds
        if (visited[row][col] != 0) return;                      // already visited
        if (grid[row][col] != target) return;                    // not part of the component

        visited[row][col] = 1;

        // If this cell is on the border, mark it
        if (checkBorder(grid, row, col, target)) {
            visited[row][col] = 100;
        }

        // DFS
        solve(grid, visited, row + 1, col, target, color);
        solve(grid, visited, row - 1, col, target, color);
        solve(grid, visited, row, col + 1, target, color);
        solve(grid, visited, row, col - 1, target, color);
    }

    bool checkBorder(vector<vector<int>>& grid, int row, int col, int target) {
        int m = grid.size(), n = grid[0].size();

        // On the grid boundary
        if (row == 0 || col == 0 || row == m - 1 || col == n - 1) return true;

        // If any neighbor is not target, it's a border
        if (grid[row + 1][col] != target) return true;
        if (grid[row - 1][col] != target) return true;
        if (grid[row][col + 1] != target) return true;
        if (grid[row][col - 1] != target) return true;

        return false;
    }
};
