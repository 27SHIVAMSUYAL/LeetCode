class Solution {
public:
    int maxDifference(string s) {

        vector<int> check(26 , 0);

   

        for(int i = 0 ; i <s.size() ; i++){
            check[ s[i] - 'a']++;
            // if(check[s[i] - 'a'] %2 == 0){ even = check[s[i] - 'a'];}
            // else{ odd = check[s[i] - 'a'];}
        }

      int even = INT_MAX ,  odd = 0;

        for( int i = 0 ; i < check.size();i++){
            if(check[i] == 0 ){continue;}
            if( check[i]%2 != 0 ){
                odd = max( odd , check[i]);
            }else {
                even = min(even , check[i]);
            }
        }



return odd - even ; 
        
        
    }
};