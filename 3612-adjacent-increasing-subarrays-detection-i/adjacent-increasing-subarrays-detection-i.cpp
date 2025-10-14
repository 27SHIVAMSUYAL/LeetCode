class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        if((nums.size() == 2 || nums.size() == 3) && k ==1){return true;}



        for(int i = 0 ; i < nums.size() ; i++){

            cout << i << i+k << endl ;
        
            if(i+k >= nums.size()){
                break;
            }

            
            if(solve(i , nums , k) && solve(i+k , nums , k)){
                return true;
            }

        }

        return false;
        
    }


    bool solve(int i , vector<int>& nums , int k){

        if(i + k > nums.size()){return false;}

        for( int j = i+1 ; j < i+k ; j++){
            if(nums[j-1] < nums[j]){
                continue;
            }else{
                return false;
            }
        }

        return true;

    }
};