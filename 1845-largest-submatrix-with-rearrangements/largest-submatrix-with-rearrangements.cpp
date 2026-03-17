class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        

        

        vector<vector<int>> cumilativeOnes(matrix.size() , vector<int>(matrix[0].size() , -1 ));

        int count = 0 ;
           int finalAnswer = INT_MIN;
           int ans = INT_MIN;

        for( int i = 0 ; i < matrix[0].size() ; i++){
            count = 0;
            for( int j = 0 ; j < matrix.size() ; j++){

                if( matrix[j][i] == 1){
                    count++;
                   
                }else{
                    count = 0;
                }
                 cumilativeOnes[j][i] = count;
                
            }
        }

      

        vector<int> row;

        for( int i = 0 ; i < matrix.size()  ; i++){
            for( int j = 0 ; j < matrix[0].size() ; j++){

                    row.push_back(cumilativeOnes[i][j]);

            }

            sort(row.begin() , row.end() ,  greater<int>() );

         


            for( int k = 0 ; k < row.size() ;k++){
              ans = (k + 1) * row[k];

                if( ans > finalAnswer){
                    finalAnswer = ans;
                }
            }

            row.clear();
        }

return finalAnswer;

    }
};