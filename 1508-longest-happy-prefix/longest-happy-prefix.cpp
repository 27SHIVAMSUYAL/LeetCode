class Solution {
public:
    string longestPrefix(string s) {

        vector<int> lps(s.size(), 0);

        int pre = 0, suff = 1;

        lps[0] = 0;

        while (suff < s.size()) {

            if (s[pre] == s[suff]) {
                pre++;
                lps[suff] = pre;
                suff++;
            } else {

                if (pre != 0) {
                    pre = lps[pre - 1];
                } else {
                    lps[suff] = 0;
                    suff++;
                }
            }
        }

        return s.substr(0 , lps[s.size()-1]);
    }
};