class Solution {
public:
    int maxOperations(string s) {

        int count = 0  , multiply = 0;
        bool flag = true;


        for( int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1'){
                // start counting;
                multiply++;
                flag = true;
            }


            if(s[i] == '0' && flag == true){
                count += multiply;
                flag = false;

            }
        }

        return count;
        
    }
};