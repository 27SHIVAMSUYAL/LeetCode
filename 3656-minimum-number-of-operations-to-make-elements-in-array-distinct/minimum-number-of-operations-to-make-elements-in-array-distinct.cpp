class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int l = nums.size();
        unordered_set<int> check;

        for(int i = l-1 ; i >=0 ; i--){

            if(check.find(nums[i]) != check.end()){

              
                    return (i+1)%3 == 0 ? (i+1)/3 : i+1 < 3 ? 1 : (i+1)/3 + 1;
                
               
            }else{
                check.insert(nums[i]);
            }

        }

        return 0;
        
    }
};