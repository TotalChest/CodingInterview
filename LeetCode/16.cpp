class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int delta = target - nums[0] - nums[1] - nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(delta))
                    delta = target - sum;
                if (sum > target) --r;
                else if (sum < target) ++l;
                else return target - delta;
            }
        }
        return target - delta;
    }
};
