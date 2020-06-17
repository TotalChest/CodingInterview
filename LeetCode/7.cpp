class Solution {
public:
    int reverse(int x) {
        long long answer = 0;
        while (x != 0) {
            answer = answer * 10 + x % 10;
            x /= 10;
        }
        if (answer > INT_MAX || answer < INT_MIN)
            return 0;
        return answer;
    }
};
