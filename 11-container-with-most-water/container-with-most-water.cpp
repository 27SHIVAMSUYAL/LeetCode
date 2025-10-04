class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxi = INT_MIN;

        int vol , length;

        int left = 0 , right = height.size()-1;

while( left < right){

    length = min(height[left] , height[right]);

    vol = length * (right - left);

    maxi = max( maxi , vol);

    if(height[left] < height[right]){
        left++;
    }else{
        right--;
    }
}


      return maxi;
        



    }
};