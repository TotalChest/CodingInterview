class Solution {
public:
    void F(vector<vector<int>> &answer, vector<int> curr, int target, vector<int> &candidates) {
        if (target == 0) {
            answer.push_back(curr);
            return;
        }
        for (auto elem: candidates)
            if (elem <= target && (curr.empty() || curr[curr.size() - 1] <= elem)) {
                vector<int> tmp = curr;
                tmp.push_back(elem);
                F(answer, tmp, target - elem, candidates);
            }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        F(answer, vector<int>(), target, candidates);
        return answer;
    }
};
