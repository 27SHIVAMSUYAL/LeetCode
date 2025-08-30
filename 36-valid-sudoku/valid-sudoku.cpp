class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        bool rows = checkRows(board);
        if (rows == false) {
            return false;
        }

        bool cols = checkCols(board);
        if (cols == false) {
            return false;
        }

       
        bool box = checkBox(board);

        if (box == false) {
            return false;
        }

        return true;
    }

    bool checkRows(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
    
        for (int i = 0; i < rows; i++) {
            vector<bool> check(10, false);
            for (int j = 0; j < cols; j++) {

                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '0';
                if (check[num] == false) {
                    check[num] = true;
                } else if (check[num] == true) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
    
        for (int i = 0; i < cols; i++) {
            vector<bool> check(10, false);
            for (int j = 0; j < rows; j++) {
                if(board[j][i] == '.'){
                    continue;
                }
                     int num = board[j][i] - '0';
                if (check[num] == false) {
                    check[num] = true;
                } else if (check[num] == true) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkBox(vector<vector<char>>&board){

        int rows = board.size();
        int cols = board[0].size();


        for(int i = 0 ; i < rows ; i=i+3){
            for(int j = 0 ; j < cols ; j=j+3){

                vector<bool> check(10,false);

                   for(int r = i ; r < i+3;r++){
                    for(int c=j ; c<j+3;c++){

                        if(board[r][c] == '.'){
                    continue;
                }
                int num = board[r][c] - '0';
                        if(check[num]==false){
                            check[num] = true;
                        }else if(check[num] == true){
                            return false;
                        }
                    }
                   } 



            }
        }

        return true;
        
    }

};