class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s==""){return 0;}
        

        int left = 0 ;

        unordered_map<char,int>mapp;
        mapp[s[0]] = 0;
        int ans = 1;

        for( int i = 1 ; i < s.size() ; i++){

                auto it = mapp.find(s[i]);

                if( it == mapp.end()){
                    mapp[s[i]] = i;
                    // explan the window 
                
                }else {
                    // found 
                        if( it->second >= left){
                            // shrink window
                            left = it->second +1;
                        }
                    // update location
                    it->second = i;
                }

              
                ans = max(ans , i - left +1);


        }
        return ans;


    }
};