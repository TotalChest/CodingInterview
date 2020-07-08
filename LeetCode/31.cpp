class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1, pos2 = n - 1;
        while (pos > 0 && nums[pos - 1] >= nums[pos])
            --pos;
        if (pos > 0) {
            while (nums[pos2] <= nums[pos - 1])
                --pos2;
            swap(nums[pos-1], nums[pos2]);
        }
        int l = pos, r = n - 1;
        while (l < r)
            swap(nums[l++], nums[r--]);
    }
};
