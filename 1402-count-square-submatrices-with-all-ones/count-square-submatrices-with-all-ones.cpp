class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int row = matrix.size(), col = matrix[0].size();
        int answer = 0;

        int mini = min(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                int maxSize = min(row-i , col-j);

                for (int k = 1; k <= maxSize; k++) {
                    if(solve(i, j, matrix, row, col, k)){
                        answer++;
                        }
                        else{
                            break;
                        }
                }
            }
        }

        return answer;
    }

    int solve(int i, int j, vector<vector<int>>& matrix, int row, int col,
              int k) {

      
        for (int r = i; r < i + k && r < row; r++) {
            for (int c = j; c <j + k && c < col; c++) {
                if (matrix[r][c] == 0) {
                    return false;
                }
            }
        }

       return true;
    }
};