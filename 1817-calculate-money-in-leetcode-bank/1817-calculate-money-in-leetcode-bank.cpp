class Solution {
public:
    int totalMoney(int n) {

        int total = 0;
        int inc = 0;
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){

            int day = i % 7;

            if(day == 0){

                total += sum;
                sum = 0;
                inc++;
                count = inc;
                sum += count;
            }else{

                count++;
                sum += count;

            }
        }

        return total + sum;

        //optimized
        /*int total = 0;
        int weekStart = 1;

        for (int i = 0; i < n; i++) {
            total += weekStart + (i % 7);
            if (i % 7 == 6) weekStart++; // move to next week's start value
        }

        return total;*/
    }
};