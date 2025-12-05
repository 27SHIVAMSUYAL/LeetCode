class Solution {
public:
    int countPartitions(vector<int>& nums) {

        vector<int> sums(nums.size() , 0);

        int sum = 0;

        for(int i = 0 ; i < nums.size() ;i++){
            sum += nums[i];
            sums[i] = sum;
        }


        int ans = 0 ;

        for(int i = 0 ; i < sums.size()-1 ; i++){
            if( abs(sums[sums.size() - 1] - 2*sums[i])%2 == 0){
                ans++;
            }
        }

        return ans;
        
    }
};