class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int pred = 2, predpred = 1;
        for (int i = 2; i < n; ++i) {
            int tmp = pred + predpred;  
            predpred = pred;
            pred = tmp;
        }
        return pred;
    }
};
