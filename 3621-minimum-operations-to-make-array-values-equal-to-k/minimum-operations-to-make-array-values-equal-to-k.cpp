class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int count = 0 ; 

        vector<bool> check(101 , false);

        sort(nums.begin() , nums.end());

      if( nums[0] < k){return -1;}


        for(int i = nums.size()-1 ; i >= 0;i--){
            if(nums[i] <= k){ break;}
            if(check[nums[i]] == false){
                    check[nums[i]] = true ;
                          count++;
            }
        }

        return count;
        
    }
};