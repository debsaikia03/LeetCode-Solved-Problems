class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();

        int maxEng = -1000;

        //dp approach - tc & sc: O(n)
        vector<int> dp(n);

        for(int i = n - 1; i >= 0; i--){

            if(i + k < n){

                dp[i] = energy[i] + dp[i + k];
            }else{

                dp[i] = energy[i];
            }

            maxEng = max(maxEng, dp[i]);
        }


        //bruteforce approach - O(n^2)
        /*for(int i = 0; i < n; i++){

            int currEng = 0;

            for(int j = i; j < n; j+=k){

                currEng += energy[j];
            }

            maxEng = max(maxEng, currEng);
        }*/

        return maxEng;
    }
};