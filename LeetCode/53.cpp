class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = nums[0];
        int n = nums.size();
        int tmp_sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (tmp_sum < 0)
                tmp_sum = 0;
            tmp_sum += nums[i];
            if (tmp_sum > answer)
                answer = tmp_sum;
        }
        return answer;
    }
};
