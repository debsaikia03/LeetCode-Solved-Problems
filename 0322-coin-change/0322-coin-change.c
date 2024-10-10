int min( int a, int b){

    return a < b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    
   int dp[coinsSize+1][amount+1];

    // Base case: With 0 coins, we cannot form any amount (except 0)
    for (int j = 1; j <= amount; j++) {
        dp[0][j] = INT_MAX - 1;  // Use INT_MAX - 1 to avoid overflow in the min operation
    }

    // Initialize the first column to 1
    for(int i=0; i <= coinsSize; i++){

        dp[i][0] = 0;
    }

    // Initialize the rest of the table to 0
    for (int i = 1; i <= coinsSize; i++) {
        for (int j = 1; j <= amount; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i=1; i <= coinsSize; i++){
        for(int j=1; j <= amount ; j++){

            if(coins[i-1] > j){

                dp[i][j] = dp[i-1][j];
            }

            else{

                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }
        
    return dp[coinsSize][amount] == INT_MAX - 1 ?  -1 : dp[coinsSize][amount];
}