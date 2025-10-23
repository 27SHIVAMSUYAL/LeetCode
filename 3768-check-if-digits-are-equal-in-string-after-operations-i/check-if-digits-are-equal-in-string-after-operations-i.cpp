class Solution {
public:
    bool hasSameDigits(string sh) {

        uint  num1 , num2 , num3;
        string ans = "";

        string s = sh;


    while(s.size() > 2){
    for(int i = 1 ; i < s.size() ; i++){
            num1 = s[i] - '0';
            num2 = s[i-1] - '0';
            num3 = (num1 + num2)%10;
            ans += num3; 
        }

        s = ans;
        ans = "";
       


}
       if( s[0] == s[s.size()-1]){
        return true;
       }else {
        return false;
       }
       

    }
};