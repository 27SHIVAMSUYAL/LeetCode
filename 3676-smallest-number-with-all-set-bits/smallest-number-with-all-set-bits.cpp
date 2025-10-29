class Solution {
public:
    int smallestNumber(int n) {

        string bit = bitset<16>(n).to_string();
        int flag = 0 ;

        cout<<"bit " << bit << '\n';
        for( char &ch : bit){
            if(flag ==1){
                ch ='1';
            }else if(ch == '1'){
                flag = 1;
            }
        }

        return stoi(bit , 0 , 2);
        
    }
};