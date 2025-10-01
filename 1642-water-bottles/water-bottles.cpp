class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int sum = 0 , emptyCount = 0  , filledBottle = numBottles;

        sum = filledBottle;
        emptyCount = filledBottle;

        while(emptyCount >= numExchange){

// getting new bottles 
            filledBottle = emptyCount/numExchange;

            emptyCount = emptyCount%numExchange;


// drinking
            sum += filledBottle;
            emptyCount += filledBottle;

        }


         return sum;


        
    }
};