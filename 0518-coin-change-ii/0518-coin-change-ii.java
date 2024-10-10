class Solution {
    public int change(int amount, int[] coins) {

        int temp[][] = new int[coins.length+1][amount+1];

        for(int i=0; i <= coins.length; i++){
            temp[i][0] = 1;
        }

        for(int i=1; i <= coins.length; i++){
            for(int j=1; j <= amount ; j++){
                if(coins[i-1] > j){
                    temp[i][j] = temp[i-1][j];
                }
                else{
                    temp[i][j] = temp[i][j-coins[i-1]] + temp[i-1][j];
                }
            }
        }
        
        return temp[coins.length][amount];
    }
}