class Solution {
public:
    bool hasSameDigits(string s) {

       int num3;
        string ans = "";

        while (s.size() > 2) {
            for (int i = 1; i < s.size(); i++) {
                num3 = (s[i] - '0' + s[i - 1] - '0') % 10;
                ans += num3;
            }

            s = ans;
            ans = "";
        }
        if (s.front() == s.back()) {
            return true;
        } else {
            return false;
        }
    }
};