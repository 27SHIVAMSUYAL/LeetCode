class Solution {
public:
    string longestNiceSubstring(string s) {

        string answer = "";

        // brute force
        for( int i = 0 ; i < s.size() ; i++){
            for( int j = 1 ; j <= s.size() - i ; j++){
                
                    check(answer , s.substr(i , j));
            }
        }

        return answer;
        
    }

    void check(string & answer , string substring){
            cout<< substring << "\n";
        unordered_set<char>sett;

        for(char ch:substring){
            sett.insert(ch);
        }

        for(char ch:substring){
            if(( islower(ch) && sett.find(toupper(ch)) != sett.end())  || ( isupper(ch) && sett.find(tolower(ch)) != sett.end()) ){
                continue;
            }else{
                return;
            }
            
        }

        if( answer.size() < substring.size()){
            answer = substring;
        }

        return ;


    }
};