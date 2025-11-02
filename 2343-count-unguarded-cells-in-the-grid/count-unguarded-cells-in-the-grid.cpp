class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        int row, col;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < walls.size(); i++) {
            row = walls[i][0];
            col = walls[i][1];
            visited[row][col] = 3;
        }

        for (int i = 0; i < guards.size(); i++) {
            row = guards[i][0];
            col = guards[i][1];
            visited[row][col] = 2;
        }

        // left to right
        int flag = 0;
        for (int i = 0; i < m; i++) {
            flag = 0;
            for (int j = 0; j < n; j++) {

                if (visited[i][j] == 3) {
                    flag = 0;
                }

                if (flag == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                }
                if (visited[i][j] == 2) {
                    flag = 1;
                }
            }
        }

        // right to left

     
        for (int i = 0; i < m; i++) {
            flag = 0;
            for (int j = n - 1; j >= 0; j--) {

                if (visited[i][j] == 3) {
                    flag = 0;
                }

                if (flag == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                }
                if (visited[i][j] == 2) {
                    flag = 1;
                }
            }
        }

        // up to down
        for (int j = 0; j < n; j++) {
            flag = 0;
            for (int i = 0; i < m; i++) {

                if (visited[i][j] == 3) {
                    flag = 0;
                }

                if (flag == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                }
                if (visited[i][j] == 2) {
                    flag = 1;
                }
            }
        }

        // down to up
        for (int j = 0; j < n; j++) {
            flag = 0;
            for (int i = m - 1; i >= 0; i--) {

                if (visited[i][j] == 3) {
                    flag = 0;
                }

                if (flag == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                }
                if (visited[i][j] == 2) {
                    flag = 1;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (visited[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};