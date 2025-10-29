class Solution {
public:

    bool checkSetBits(int n){

        while(n > 0){

            if(n % 2 == 0) return false;

            n /= 2;
        }

        return true;
    }

    int smallestNumber(int n) {

        while(n <= INT_MAX){

            if(!checkSetBits(n)) n++;

            else return n;
        }

        return -1;
    }
};