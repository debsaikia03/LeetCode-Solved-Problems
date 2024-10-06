//house robber

int max(int m, int n){

   return (m > n)? m : n;
}

int rob(int* nums, int numsSize) {

    if(numsSize == 1){

        return nums[0];
    }
    
    if(numsSize == 2){

        return max(nums[0], nums[1]);
    }

    int dp[numsSize];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < numsSize; i++){

       dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[numsSize - 1];
}