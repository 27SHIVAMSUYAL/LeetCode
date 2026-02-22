class Solution {
public:
    int binaryGap(int n) {

      string binary = "";
      int lastPosition = -1;
      int distance = 0;
      int length = 0;
      while( n > 0){
        length++;
        if( n%2 == 0){
            binary.push_back('0');
            n = n/2;
        } else {
            binary.push_back('1');

            if( lastPosition == -1){
                lastPosition = length;
            }
            if((length - lastPosition ) > distance ){
                distance = length - lastPosition ;
            }
            lastPosition = length;
            n = (n-1)/2;
        }
      }

      cout<< "binary number -> " << binary;
      return distance;

        
    }
};