class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size() - 1;

        while(n >= 0 && (num[n] - '0') % 2 == 0){

            n--;
        }

        return n < 0 ? "" : num.substr(0, n+1);
    }
};