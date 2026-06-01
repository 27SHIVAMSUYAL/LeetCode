class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin() , cost.end());
        int n = cost.size();
        int total = 0;
        int flag = 1;

        for( int i = n - 1; i >=0 ; i--){

            if( flag == 1 || flag == 2){
                total += cost[i];
                flag++;
            }else{
                flag = 1;
            }

        }

        return total;
        
    }
};