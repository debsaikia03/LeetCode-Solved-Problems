class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n; // Use long long to safely handle INT_MIN
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1;

        while(N > 0){

            if(N % 2 == 1){
                ans = ans * x;
                N--;
            }

            else{
                N = N / 2;
                x = x * x;
            }
        }

        return ans;
    }
};