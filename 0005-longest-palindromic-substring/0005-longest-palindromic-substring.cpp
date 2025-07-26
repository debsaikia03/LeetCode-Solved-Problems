class Solution {
public:

    int dp[1001][1001];

    bool solve(string &s, int l, int r){
         
        if(l >= r) return true;

        if(dp[l][r] != -1)
            return dp[l][r];

        if(s[l] == s[r]) 
            return dp[l][r] = solve(s, l+1, r-1);

        return dp[l][r] = false;
    }

    string longestPalindrome(string s) {
       
        int n = s.size();

        int maxL =  INT_MIN;

        int startIdx = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j-i+1 > maxL && solve(s, i, j)){
                    startIdx = i;
                    maxL = j-i+1;
                }    
            }
        }

        return s.substr(startIdx, maxL);
    }
};
