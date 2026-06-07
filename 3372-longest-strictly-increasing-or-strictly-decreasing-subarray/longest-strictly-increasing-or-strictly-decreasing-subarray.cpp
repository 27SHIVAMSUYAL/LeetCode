class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int count = 1;
        int answer = 1;
        int flag = 1;
        // flag -> 1 for increasing
        // flag -> 0 for decreasinig

        if(nums[1] < nums[0]){
            flag = 0;
        }

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {
                if (flag != 1) {
                    count = 1;
                    flag = 1;
                }
                count++;

            } else if (nums[i] < nums[i - 1]) {
                if (flag != 0) {
                    count = 1;
                     flag = 0;
                }
                count++;
            } else {
                count = 1;
            }

            answer = max(answer , count);
        }


        return answer;
    }
};