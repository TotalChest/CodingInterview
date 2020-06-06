class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = make_pair(nums[i], i);
        sort(A.begin(), A.end());
        int l = 0, r = n - 1;
        while(l < r) {
            if (A[l].first + A[r].first == target)
                return {A[l].second, A[r].second};
            if (A[l].first + A[r].first > target)
                --r;
            else
                ++l;
        }
        return {0, 10};
    }
};