class Solution {
public:
    bool checkStrings(string s1, string s2) {

    map< char , int> even , odd;


    for( int i = 0 ; i < s1.size() ;i++ ){
        
        if(i%2 == 0){

            if( even.find(s1[i])  == even.end()){
                even[s1[i]] = 1;
            }else{
                even[s1[i]]++;
            }
            
        }else{

            if( odd.find(s1[i])  == odd.end()){
                odd[s1[i]] = 1;
            }else{
                odd[s1[i]]++;
            }
        }
        
    }

    for( int i = 0 ; i < s2.size() ; i++){
        if( i%2 == 0){
            if( even.find(s2[i]) != even.end()){
                even[s2[i]]--;
            }

        }else{
            if( odd.find(s2[i]) != odd.end()){
                odd[s2[i]]--;
            }
            
        }
    }


    

    for( pair<char , int > p : even){
        if(p.second != 0){
            return false;
        }
    }


    for( pair<char , int > p : odd){
      if(p.second != 0){
        return false;
      }
    }

    return true;




      
        
    }
};