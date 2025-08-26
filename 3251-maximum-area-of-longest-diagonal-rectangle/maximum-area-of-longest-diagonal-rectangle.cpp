class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimentions) {

        double maxDiagonal = dimentions[0][0]*dimentions[0][0] + dimentions[0][1]*dimentions[0][1];
        int maxArea = dimentions[0][0]*dimentions[0][1];

        for(int i = 0 ; i < dimentions.size();i++){

            double dia = dimentions[i][0]*dimentions[i][0] + dimentions[i][1]*dimentions[i][1];
            int area = dimentions[i][0]*dimentions[i][1];
            if(dia > maxDiagonal){
                maxDiagonal = dia;
                maxArea = area;
            }else if( dia == maxDiagonal){
                    
                    if(area > maxArea){
                        maxArea = area;
                    }
            }

        }

        return maxArea;
        
    }
};