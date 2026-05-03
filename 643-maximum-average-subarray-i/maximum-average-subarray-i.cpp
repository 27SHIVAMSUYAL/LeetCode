class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum = 0;
        for( int i = 0 ; i < k ; i++){
            sum += nums[i];
        }
            int front = k;

            double ans = sum / k , avg;

        while( front < nums.size() ){

            sum += nums[front] - nums[front - k];
           avg = sum / k;
            ans = max(ans,avg);
            front++;
        }

        return ans;
        
    }
};