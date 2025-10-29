class Solution {
public:
    int smallestNumber(int n) {

        string binary = "";
        int ans=0;
        int digit;

        while (n > 0) {
            digit = n % 2;
            binary = to_string(digit) + binary;
            n = n / 2;
        }

        cout << "binary" << binary << '\n';

        for (char& ch : binary) {
            ch = '1';
        }

        cout << "binary" << binary << '\n';

        int power = 0;
        int num = stoi(binary);

        cout << "num" << num << '\n';

        while (num > 0) {

            digit = num % 10;
            cout<< "digit" << digit << '\n';
            if( digit == 1){
                 ans += pow(2, power);
            }
        
            power++;
            num = num / 10;
        }
        cout << "ans" << ans << '\n';

        return ans;
    }
};