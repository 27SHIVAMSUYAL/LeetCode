class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        set<int> check;
        int count = 0;
        int start = 0 ;
          bool pass = false;


        while( start < nums.size() && pass == false){


            for(int i = start; i < nums.size();i++){
                if(check.find(nums[i]) != check.end()){

                    start += 3;
                    count++;
                    check.clear();
                    pass = false;
                    break;

                }else{
                    check.insert(nums[i]);
                    pass = true;
                }
            }
           

        }

        return count ;
        
    }
};