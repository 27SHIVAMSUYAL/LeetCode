class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
if(nums.size()==1){
    if(nums[0]==0){
        return 0;
    }
}
vector<int> system;

int count = 0 ;
int maxCount = 0; 
        for( int i = 0 ; i < nums.size();i++){
                if( nums[i]==1){
                    count++;
                    maxCount = max(maxCount , count);
                    if(i==nums.size()-1){
                          system.push_back(count);
                            count=0;
                            break;
                    }
                }
                else {
                            system.push_back(count);
                            count=0;
                }
        }

int maxSum = maxCount-1;
        for(int i = 0 ; i < system.size()-1;i++){
               maxSum = max(system[i] + system[i+1] , maxSum);
        }

        return maxSum;
    }
};