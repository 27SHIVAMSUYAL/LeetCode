class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {


            int n = colors.size() , count=0 , one , two , three;
        for( int i = 0 ; i < n ; i++){
        one = i ;
        two = (i+1)%n;
       three = (i+2)%n;
    
        if( colors[one] != colors[two] && colors[two] != colors[three]){
           
            count++;
        }

        }

        return count;
        
        
    }
};