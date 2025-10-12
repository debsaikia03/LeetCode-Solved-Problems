class Solution {
public:
    int kthFactor(int n, int k) {

        for(int i = 1; i <= sqrt(n); i++){

            if(n % i == 0){

                k--;
            }
            if(k == 0) return i;
        }

        if(k != 0){

            for(int i = sqrt(n); i >= 1; i--){

                if(n % i == 0 && i * i != n){

                    k--;

                } 
                if(k == 0) return n / i;
            }
        }

        return -1;
    }
};