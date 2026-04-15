class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {


        // move in both directions and keep counting . 

        int left = startIndex , right = startIndex ;
        int ld = 0 , rd = 0;

        for( int i = 0 ; i < words.size() ; i++){
             if(words[left] == target){
                    return ld;
                }

                 if(words[right] == target){

                    return rd;
                }




            if( left == 0 ){
                left = words.size() - 1;
                ld++;
            }else{
                left--;
                ld++;
            }
            

            if( right == words.size() - 1){
                right = 0;
                rd++;
                
            }else{
                right++;
                rd++;
            }
            

        }



        return -1;
        
    }
};