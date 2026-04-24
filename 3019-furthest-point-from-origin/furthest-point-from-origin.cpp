class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {


        // jo jayada h vahi direction mein jao 

        int left =  0 , right = 0 , dot = 0;

        for( char ch : moves){
            if(ch == 'L'){
                left++;
            }else if (ch == 'R'){
                right++;
            }else{
                dot++;
            }
        }

        return abs(left - right )+ dot;
        
    }
};