class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow on abs(INT_MIN)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            int count = 0;

            // Find the largest multiple such that (b * 2^count) <= a
            while (a >= temp * pow(2, count + 1)) {
                count++;
            }

            ans += pow(2, count);       // Add 2^count to result
            a -= temp * pow(2, count);  // Subtract b * 2^count from dividend
        }

        // Determine the sign of the result
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        // Clamp result to 32-bit integer range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};
