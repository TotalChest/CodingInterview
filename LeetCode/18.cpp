class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { 
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1])
                    continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target)
                        answer.push_back({nums[i], nums[j], nums[l], nums[r]});
                    if (sum > target)
                        while(l < --r && nums[r] == nums[r + 1]);
                    else
                        while(++l < r && nums[l] == nums[l - 1]);
                }
            }
        }
        return answer;
    }
};
