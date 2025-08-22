class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size() , col = grid[0].size();

        int rowMin=INT_MAX,rowMax=INT_MIN , colMin=INT_MAX,colMax=INT_MIN;
            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j <col ;j++){
                        if(grid[i][j]==1){
                            rowMin= min(rowMin , i);
                                rowMax= max(rowMax , i);
                                colMin =min(colMin ,j);
                                colMax=max(colMax , j);
                        }
                }
            }

            int answer = ((rowMax-rowMin)+1) *((colMax-colMin)+1);


            return answer;

    }
};