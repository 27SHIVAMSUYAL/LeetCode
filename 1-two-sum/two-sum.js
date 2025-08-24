/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    


    let l = nums.length;

    var um = {};

    for( let i =0 ; i < l;i++){
        if(target - nums[i] in um){
        return [i,um[target-nums[i]]];
        }else {
            um[nums[i]]=i;
        }
    }

    return ;
};