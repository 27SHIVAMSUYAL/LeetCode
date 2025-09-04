class Solution {
public:
    int findClosest(int x, int y, int z) {

     
        return  x==y? 0 : (abs(y-z) > abs(x-z) ) ? 1 : (abs(y-z) < abs(x-z) )? 2 : 0 ;
        
    }
};