class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int totDrink = numBottles;

        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){

            totDrink++;
            emptyBottles = emptyBottles - numExchange + 1;
            numExchange++;
        }
        
        return totDrink;
        
    }
};