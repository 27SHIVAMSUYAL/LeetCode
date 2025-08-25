class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<int> answer;
        int row = 0, col = 0;

        bool up = true;
        while (answer.size() < m * n) {

            answer.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {
                    row++;
                    up = false;
                }else if (row == 0) {
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    up = true;
                }else if (col == 0) {
                    row++;
                    up = true;
                } else {
                    col--;
                    row++;
                }
            }
        }

        return answer;
    }
};