class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> toCheckVec = {{0, 0}, {0, 3}, {0, 6},
                                          {3, 0}, {3, 3}, {3, 6},
                                          {6, 0}, {6, 3}, {6, 6}};
        int toCheck = 0;



        for (int i = 0; i < board.size(); i++) {
            if (checkRow(i, board) == false) {
                return false;
            }
        }

        for (int j = 0; j < board[0].size(); j++) {
            if (checkCol(j, board) == false) {
                return false;
            }
        }

        while(toCheck != 9) {
            if (checkBox(board, toCheckVec, toCheck) == false) {
                return false;
            }
            toCheck++;
        }

        return true;
    }

    bool checkRow(int i, vector<vector<char>>& board) {

        vector<int> count(10, 0);

        for (int j = 0; j < board[i].size(); j++) {

            if (board[i][j] == '.') {
                continue;
            }

            if (count[board[i][j] - '0'] == 1) {
                return false;
            } else {
                count[board[i][j] - '0']++;
            }
        }

     
        return true;
    }

    bool checkCol(int j, vector<vector<char>>& board) {
      

        vector<int> count(10, 0);

        for (int i = 0; i < board.size(); i++) {

            if (board[i][j] == '.') {
                continue;
            }

            if (count[board[i][j] - '0'] == 1) {
                return false;
            } else {
                count[board[i][j] - '0']++;
            }
        }

       
        return true;
    }

    bool checkBox(vector<vector<char>>& board, vector<vector<int>>& toCheckVec,
                  int toCheck) {

        vector<int> count(10, 0);
        int i = toCheckVec[toCheck][0];
        int j = toCheckVec[toCheck][1];

        for (int row = i; row < i + 3; row++) {
            for (int col = j; col < j + 3; col++) {

                if (board[row][col] == '.') {
                    continue;
                }

                if (count[board[row][col] - '0'] == 1) {
                    return false;
                } else {
                    count[board[row][col] - '0']++;
                }
            }
        }

        return true;
    }
};