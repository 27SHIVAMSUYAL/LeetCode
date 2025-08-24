/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
let profit = 0 , min = Number.MAX_SAFE_INTEGER;
    for(let i = 0 ; i <prices.length ; i++){
        if( prices[i] < min){
            min = prices[i];
        }else {
            profit = Math.max(prices[i]-min , profit);
        }
    }

    return profit;
};