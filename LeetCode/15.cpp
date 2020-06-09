class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1])
                        ++l;
                    ++l;
                    --r;
                }
                else if (nums[l] + nums[r] > target)
                    --r;
                else
                    ++l;
            }
        }
        return answer;
    }
};
