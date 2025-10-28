class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int count = 0;

        for( int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0  ){
                if(check(nums,nums[i] , i , 1) ){
                    count++;
                }
                if(check(nums,nums[i] , i , -1) ){
                    count++;
                }
            }
            
        }

        return count;


        
    }

    bool check( vector<int> nums , int element , int curr , int direction){

        if(direction == 1){
            curr++;
        }else{
            curr--;
        }

        while(curr >= 0 && curr < nums.size()){

            if(nums[curr] == 0){
                curr = curr + direction;
            }else{
                direction = ( direction )* (-1);
                nums[curr]--;
                 curr = curr + direction;
            }
            
        }

        return checkValid(nums);
        
        
    }

    bool checkValid(vector<int> nums){
        for(int i : nums){
            if( i != 0){
                return false;
            }
        }
        return true;
    }
};