class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        int found = -1;
        while (left <= right) {

            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                found = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }


        if( found == -1){
            vector<int> ans(2,-1);
            return ans;
        }else{
            return solve(found,nums,target);
        }

    }


    vector<int> solve( int found , vector<int>&nums , int &target){
        int left = found , right = found;

        while(left >0){
            if(nums[left-1]==target){
                    left--;
            }else{
                break;
            }
        }  

          while(right < nums.size()-1){
            if(nums[right+1]==target){
                    right++;
            }else{
                break;
            }
        }     

        return {left,right}; 

    }
};