class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;
        long long num = (long long) x * sign;  // convert safely
        long long revNum = 0;

        while (num > 0) {
            int digit = num % 10;
            num /= 10;

            revNum = revNum * 10 + digit;
            if (revNum > INT_MAX) return 0;
        }

        return (int)(revNum * sign);
    }
};
