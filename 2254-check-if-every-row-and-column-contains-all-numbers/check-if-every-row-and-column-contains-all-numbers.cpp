class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {


        int n = matrix.size();

        vector<int>count(n+1,0);

        int sum = n*(n+1) / 2;

        for(int i = 0 ; i < n ;i++){
          if(checkRow( i , matrix  , n , count , sum) == false){
            return false;
          }
        }

        for(int j = 0 ; j < n ; j++){
          if(checkCol( j , matrix  , n , count , sum) == false){
            return false;
          }
        }

        return true;
        
    }

    bool checkRow( int i , vector<vector<int>>& matrix , int n , vector<int> count ,int sum){

    

        for(int j = 0 ; j < n ; j++){
            if(count[ matrix[i][j] ] == 0){
                count[ matrix[i][j] ]++;
                sum -= matrix[i][j];
            }
        }

        if(sum == 0 ){return true;}

        return false;


    }

    bool checkCol( int j , vector<vector<int>>& matrix , int n , vector<int> count , int sum){

    

        for(int i = 0 ; i < n ; i++){
            if(count[ matrix[i][j] ] == 0){
                count[ matrix[i][j] ]++;
                 sum -= matrix[i][j];

            }
        }

          if(sum == 0 ){return true;}

        return false;


    }
};