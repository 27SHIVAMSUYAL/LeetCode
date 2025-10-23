class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size(), col = matrix[0].size();

        unordered_set<int> rowSet, colSet;

        vector<bool> visitedRow(row, false);
        vector<bool> visitedCol(col, false);
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if( matrix[i][j] == 0){
                    visited[i][j] = true;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                

                    if (visited[i][j] == true) {

                        if (visitedRow[i] != true) {
                            makeZeroRow(i, matrix);
                         
                        }

                        if (visitedCol[i] != true) {
                            makeZeroCol(j, matrix);
                           
                        }
                    }
                
            }
        }

        return;
    }

    void makeZeroRow(int i, vector<vector<int>>& matrix) {

        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = 0;
           
        }
        return;
    }
    void makeZeroCol(int j, vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][j] = 0;
            
        }
        return;
    }
};