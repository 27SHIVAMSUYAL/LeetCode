class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

      

        vector<string>answer;
          if(s.size() < 10){
            return answer;
        }

        unordered_map<string,int>mapp;

        string ss;

        for( int i = 0 ; i <= s.size()-10 ; i++){
            ss = s.substr(i, 10);
            auto it = mapp.find(ss);

            if(it == mapp.end()){
                mapp[ss]=0;
            }else if(it->second == 0){
                answer.push_back(ss);
                it->second++;
            }
        }

        return answer;
        
    }
};