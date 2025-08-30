class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> sufixSum(n);
          int suSum = nums[n-1];

        vector<int> prefixSum(n);
        int preSum = nums[0];

        for( int i = 0 ; i < n ; i++){
              if(nums[i] > preSum){
                preSum = nums[i];
              }
                prefixSum[i]=preSum;
        }

         for( int i = n-1 ; i >= 0 ; i--){
              if(nums[i] > suSum){
                suSum = nums[i];
              }
                sufixSum[i]=suSum;
        }

        


long long  ans = 0 , cal;

        for( int i = 1 ; i < n-1 ; i++){
long long left = prefixSum[i-1];
long long mid =  nums[i];
long long right = sufixSum[i+1];
            

          cal = (left -mid)*right;

            if( ans < cal){
                ans = cal;
            }
        }

        return ans;


        
    }
};