class Solution {
public:
    bool judgeCircle(string moves) {
        
        int xAxis = 0 ,yAxis = 0;

        for( char ch : moves){
            if( ch == 'R'){
                xAxis++;
            }else if (ch == 'L') {
                    xAxis--;
            }else if (ch == 'U'){
                    yAxis++;
            }
            else {
                    yAxis--;
            }
            
        }

    return( xAxis == 0 && yAxis == 0);
    }
};