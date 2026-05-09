class Solution {
public:
    int countGoodSubstrings(string s) {

        int n = s.size() , answer = 0;

        for( int i = 0 ; i < n-2 ; i++){
            

                check(s,i , i+2 , answer);

            
        }

        return answer;
        
    }

    void check(string &s , int i , int j , int &answer){
        unordered_set<char> sett;
        cout<< "\n";
        while(i <= j ){
                 cout<< i;
            auto it = sett.find(s[i]);

            if(it == sett.end()){
                sett.insert(s[i]);
                
            }else{
                return;
            }
            i++;

        }
        answer++;
        return;

    }



};