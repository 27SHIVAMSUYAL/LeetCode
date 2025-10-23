class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int row = board.size(), col = board[0].size(),  live, non , check =1;
        pair<int, int> count;

        vector<vector<int>> copy = board;

        

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                count = checkLive(i, j, copy);

                live = count.first;
                non = count.second;
                cout<<" live " << live << " non " << non <<'\n';

                if (board[i][j] == 1) {

                    if (live < 2) {
                        board[i][j] = 0;
                       
                    } else if (live > 3) {
                        board[i][j] = 0;
                       
                    }

                } else {
                    if (live == 3) {
                        board[i][j] = 1;
                         
                    }
                }
            

        }
        
        }

        return;
    }

    pair<int, int> checkLive(int row, int col, vector<vector<int>> board) {

        int live = 0;
        int non = 0;
        int curRow, curCol;

        vector<int> sign = {1, -1, 0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (sign[i] == 0 && sign[j] == 0) {
                    continue;
                }

                curRow = row + sign[i];
                curCol = col + sign[j];

                if (curRow >= 0 && curRow < board.size() && curCol >= 0 &&
                    curCol < board[0].size()) {
                    if (board[curRow][curCol] == 1) {
                        live++;
                    } else {
                        non++;
                    }
                }
            }
        }

        return {live, non};
    }
};