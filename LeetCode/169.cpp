class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0)
                answer = nums[i];
            count += (nums[i] == answer) ? 1 : -1;
        }
        return answer;
    }
};
