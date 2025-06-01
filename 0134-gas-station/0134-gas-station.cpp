class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totGas = 0, totCost = 0;

        for(int i : gas){
            totGas += i;
        }

        for(int i : cost){
            totCost += i;
        }

        if(totGas < totCost) return -1;

        int start = 0, currGas = 0;

        for(int i = 0; i < gas.size(); i++){

            currGas += gas[i] - cost[i];

            if(currGas < 0){

                start = i+1;
                currGas = 0;
            }
        }

        return start;
    }
};