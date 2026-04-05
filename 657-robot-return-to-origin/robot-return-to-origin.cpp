class Solution {
public:
    bool judgeCircle(string moves) {
        
        int xAxis = 0 ,yAxis = 0;

        for( char ch : moves){
           
           switch(ch){
            case 'R':
            xAxis++;
                break;
            case 'L':
            xAxis--;
                break;
            case 'U':
            yAxis++;
                break;
            default:
                yAxis--;
                break;
           }
            
        }

    return( xAxis == 0 && yAxis == 0);
    }
};