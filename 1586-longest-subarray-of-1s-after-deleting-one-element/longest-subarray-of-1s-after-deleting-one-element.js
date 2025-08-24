/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {

    let system = [];

    if(nums.length ==1 && nums[0]==0 ){
            return 0;
    }
    let count =0 , maxCount = 0;

        for(let i = 0 ; i <nums.length ; i++){
            if(nums[i]==1){
                count++;
                maxCount = Math.max(maxCount , count);
            }else{
                   system.push(count);
                    count=0;
            }
        }

       if(count!=0){ system.push(count);}

    
    if (system.length === 1 && nums.length === system[0]) {
        return nums.length - 1;
    }

var maxSum = 0;

        for( let i = 0 ; i <system.length-1 ; i++){
            maxSum = Math.max( maxSum , system[i]+system[i+1]);
        }

        return maxSum;


};