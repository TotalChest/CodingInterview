class Solution {
public:
    int myAtoi(string str) {
        long long answer = 0;
        int curr = 0, n = str.size(), sign = 1;;
        enum STATE {P1, P2, P3, P4} ST = P1;
        while (curr < n) {
            if (ST == P1) {
                if (str[curr] == '-') {
                    ST = P2;
                    sign = -1;
                }
                else if (str[curr] == '+')
                    ST = P2;
                else if (str[curr] >= '0' && str[curr] <= '9') {
                    ST = P3;
                    answer = answer * 10 + (str[curr] - '0');
                }
                else if (str[curr] != ' ')
                    return 0;
            }
            else if (ST == P2) {
                if (str[curr] >= '0' && str[curr] <= '9') {
                    ST = P3;
                    answer = answer * 10 + (str[curr] - '0');
                }
                else
                    return 0;
            }
            else if (ST == P3) {
                 if (str[curr] >= '0' && str[curr] <= '9') {
                    ST = P3;
                    if (answer > INT_MAX && sign == 1)
                        return INT_MAX;
                    if (answer > INT_MAX && sign == -1)
                        return INT_MIN;
                    answer = answer * 10 + (str[curr] - '0');
                }
                else
                    ST = P4;
            }
            else if (ST == P4) {
                break;
            }
            ++curr;
        }
        if (ST != P3 && ST != P4)
            return 0;
        answer = answer * sign;
        if (answer > INT_MAX) return INT_MAX;
        if (answer < INT_MIN) return INT_MIN;
        return answer;
    }
};
