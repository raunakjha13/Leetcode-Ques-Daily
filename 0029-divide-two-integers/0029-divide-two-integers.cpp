class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Check whether answer should be negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and make both positive
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Keep doubling divisor
            while (a >= temp + temp) {
                temp += temp;
                multiple += multiple;
            }

            a -= temp;
            ans += multiple;
        }

        if (negative)
            ans = -ans;

        return (int)ans;
    }
};