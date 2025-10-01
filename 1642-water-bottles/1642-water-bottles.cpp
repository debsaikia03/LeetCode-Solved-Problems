class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int totDrink = numBottles;

        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){

            totDrink += (emptyBottles / numExchange);
            int remainingEmpty = emptyBottles % numExchange;
            emptyBottles = (emptyBottles / numExchange);
            emptyBottles +=  remainingEmpty;
        }
        
        return totDrink;
        
    }
};