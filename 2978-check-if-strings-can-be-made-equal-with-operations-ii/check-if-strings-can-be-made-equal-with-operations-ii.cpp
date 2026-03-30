class Solution {
public:
    bool checkStrings(string s1, string s2) {

    vector<char> s1Even , s1Odd , s2Even , s2Odd;


    for( int i = 0 ; i < s1.size() ;i++ ){
        
        if(i%2 == 0){
            s1Even.push_back(s1[i]);
        }else{
            s1Odd.push_back(s1[i]);
        }
        
    }

    for( int i = 0 ; i < s2.size() ; i++){
        if( i%2 == 0){
            s2Even.push_back(s2[i]);

        }else{
            s2Odd.push_back(s2[i]);
        }
    }


    sort(s1Even.begin() , s1Even.end());
    sort(s2Odd.begin() , s2Odd.end());
    sort(s2Even.begin( ) , s2Even.end());
    sort(s1Odd.begin() , s1Odd.end());


    for( int i = 0 ; i < s1Even.size() ;i++){
        if(s1Even[i] != s2Even[i]){
            return false;
        }
    }


    for( int i = 0 ; i < s2Odd.size() ; i++){
        if( s2Odd[i] != s1Odd[i]){
            return false;
        }
    }

    return true;




      
        
    }
};