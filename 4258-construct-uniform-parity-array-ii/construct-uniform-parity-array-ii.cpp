class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        

        int mini = INT_MAX;

        if( odd(mini , nums1)){
            return true;
        }else if(even(mini , nums1)){
            return true;
        }
        return false;
    }

    void findMini(int &mini , vector<int>&nums , int flag){
        for( int i = 0 ; i < nums.size() ; i++){
            if( flag == 0 && nums[i]%2 == 0){
                mini = min(nums[i] , mini);
            }else if (flag == 1 && nums[i]%2 != 0){
                mini = min(nums[i] , mini);
            }
        }
    }

    bool odd(int &mini , vector<int>&nums1 ){
        mini = INT_MAX;
        findMini(mini , nums1 , 1);
        vector<int>nums2;
        for(int i = 0 ; i < nums1.size(); i++){
            if(nums1[i]%2 != 0){
                nums2.push_back(nums1[i]);
            }else if(nums1[i] - mini >= 1 && ( nums1[i] - mini )%2 != 0 ){
                nums2.push_back(nums1[i]);
            }else{
                return false;
            }
        }
        return true;
        
    }


    bool even(int &mini , vector<int>&nums1 ){
        mini = INT_MAX;
        findMini(mini , nums1 , 0);
        vector<int>nums2;
        for(int i = 0 ; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){
                nums2.push_back(nums1[i]);
            }else if(nums1[i] - mini >= 1 && ( nums1[i] - mini )%2 == 0 ){
                nums2.push_back(nums1[i]);
            }else{
                return false;
            }
        }
        return true;
        
    }
};