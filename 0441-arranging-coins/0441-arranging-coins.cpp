class Solution {
public:
    int arrangeCoins(int n) {
        
        int count = 0;
        int row = 1;

        while(n > 0){

            if(row <= n){
 
                count++;
                n = n - row;
                row++;
            }

            else{
                break;
            }
        }

        return count;
    }
};