class Solution {
public:
    void generate(vector<vector<int>> &answer, vector<int> nums, vector<int> curr) {
        if (nums.size() == 0) {
            answer.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp = nums;
            tmp.erase(tmp.begin() + i);
            curr.push_back(nums[i]);
            generate(answer, tmp, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        generate(answer, nums, vector<int>());
        return answer;
    }
};
