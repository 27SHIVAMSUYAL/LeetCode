/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    let profit = 0  , min = Number.MAX_SAFE_INTEGER , max = Number.MIN_SAFE_INTEGER;

    let mp = new Map();

    for( let i = 0 ; i < prices.length ; i++){
        if(prices[i] < min){
            min=prices[i];
            mp.set(prices[i] , i);
            max = Number.MIN_SAFE_INTEGER;
        }else if( prices[i] > max && mp.get(min)<i){
                profit = Math.max(profit , prices[i]-min);
                max = prices[i];
        }
    }


    return profit;
    
};