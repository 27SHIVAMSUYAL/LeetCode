class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {


            if( check(mat , target) ) {
                return true;
            }
              
        for (int i = 0; i < 3; i++) {

            rotate(mat);
            if (check(mat, target)) {
                return true;
            }
        }

        return false;
    }

    void rotate(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        // transpose the matix

        for (int i = 0; i < rows; i++) {
            for (int j = i; j < cols; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // reverse each row

        for (int i = 0; i < rows; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool check(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (target[i][j] != mat[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};