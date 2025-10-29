class Solution {
public:
    int smallestNumber(int n) {

       // create the binary

       int ans = 0 ;
       int digit;

       string binary = "";
      
       while( n > 0){
        digit = n%2;
        binary = to_string(digit) + binary;
        n = n/2;
       }
       int power = 0;
       int num = stoi(binary);
       
       while( num > 0 ){
        digit = num%10;

            ans += pow(2 , power);

        power++;
        num = num/10;
       }

       return ans;
        
    }
};