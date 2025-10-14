class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {


        vector<vector<int>> ans(n , vector<int>(n , -1));
        vector<vector<bool>> visited(n , vector<bool>(n , false));
        int row = 0 , col = 0;

        vector<pair<int,int>> dir = {{0,1} , {1,0} , {0 , -1} , {-1 , 0}};
        int direction = 0 ;

        for(int i = 1 ; i <= n*n ; i++){

            ans[row][col] = i;
            visited[row][col] = true;

            if(direction == 0 && col+1 < n && !visited[row][col+1]){ // go right

                    row = row + dir[direction].first;
                    col = col + dir[direction].second;

            }else if(direction == 1 && row +1 < n  && !visited[row +1][col]){ // go down

                row = row + dir[direction].first;
                    col = col + dir[direction].second;
            }else if(direction == 2 && col -1 >= 0  && !visited[row][col-1]){ // go left

               row = row + dir[direction].first;
                    col = col + dir[direction].second;
            }else if( direction == 3 && row-1 >= 0  && !visited[row-1][col]) { // go up
            
                row = row + dir[direction].first;
                    col = col + dir[direction].second;

            }else{
                direction =  ( direction + 1 ) % 4;
                row = row + dir[direction].first;
                    col = col + dir[direction].second;
            }
            

        }

        return ans;
        
    }
};