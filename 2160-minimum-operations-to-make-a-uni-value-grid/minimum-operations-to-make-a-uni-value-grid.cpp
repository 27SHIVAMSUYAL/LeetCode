class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size(), col = grid[0].size();

        int count = 0 ;
        vector<int>arr;
        int remainder =grid[0][0]%x;
        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {
  
                arr.push_back(grid[i][j]);
                if(grid[i][j]%x != remainder){
                    return -1;
                }
            }
        }

        sort(arr.begin(),arr.end());
        int mid = arr.size()/2;
        int median = arr[mid];

        for(int i = 0 ; i < arr.size();i++){
            count += abs(arr[i]-median)/x;
        }
       
        return count;
    }
};