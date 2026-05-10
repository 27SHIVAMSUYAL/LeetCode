class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int ans = INT_MAX;
        int n = nums.size();
        int right = 0 , left = 0;

        int sum = 0 , length;

        while(right < n){

            sum += nums[right];

            

            while( sum >= target ){
                // valid
                length = right - left + 1;
                ans = min( ans , length );
                cout<<" left " << left << " right " << right << "\n";
               
                // shink
                sum -= nums[left];
                left++;
                
            }

             // expand
                    right++;

        }

        return ans == INT_MAX?0:ans;


    }
};