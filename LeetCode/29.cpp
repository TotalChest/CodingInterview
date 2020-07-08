class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        unsigned int divd = abs(dividend);
        unsigned int divs = abs(divisor);
        unsigned int answer = 0;
        int red = divs;
        int s = 1;
        while (divd >= divs) {
            divd -= red;
            answer += s;
            red += divs;
            ++s;
            if (red > divd) {
                red = divs;
                s = 1;
            }
        }
        return ((dividend < 0)^(divisor < 0) ? -1 : 1) * answer;
    }
};
