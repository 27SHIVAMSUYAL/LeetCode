class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;

        for( int i = 0 ; i < words.size() ; i++){
            if(check(words[i] , x)){
                ans.push_back(i);
            }
        }

        return ans;
        
    }

    bool check(string word , char x){
        for(char ch : word){
            if(ch == x){
                return true;
            }
        }

        return false;
    }
};