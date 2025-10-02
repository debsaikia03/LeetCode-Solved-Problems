class Solution {
public:

    //using recursion - time limit exceeded - create dp array - again time limit exceeded - use tabulation 
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){

        if(i == n - 1){

            return triangle[n-1][j];
        }

        if(dp[i][j] != -1) return dp[i][j]; //memoization - no need to recurse further if previously calculated

        int goDown = triangle[i][j] + f(i+1, j, triangle, n, dp);
        int goDiagonal = triangle[i][j] + f(i+1, j+1, triangle, n, dp);

        return dp[i][j] = min(goDown, goDiagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        //since it's an overlapping subproblem we can use memoization

        vector<vector<int>> dp(n, vector<int>(n, -1));

        //return f(0, 0 ,triangle, n, dp); 
        //recursion + memoization - time limit exceeded - O(n^2)

        //using tabulation - optimal approach

        for(int j = 0; j < n; j++){

            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){

                int goDown = triangle[i][j] + dp[i+1][j];
                int goDiagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(goDown, goDiagonal);
            }
        }

        return dp[0][0];
    }
};