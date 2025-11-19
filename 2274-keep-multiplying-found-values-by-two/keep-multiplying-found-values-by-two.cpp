class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        unordered_set<int> set;

        for(int i = 0 ; i < nums.size() ; i++){

            set.insert(nums[i]);

        }

        while( true){
            if(set.find(original) != set.end()){
                original *= 2;

            }else{
                break;
            }
        }


        return original;
        
    }
};