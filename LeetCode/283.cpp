class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr_l = 0, curr_r = -1;
        while (++curr_r < nums.size())
            if (nums[curr_r])
                swap(nums[curr_l++], nums[curr_r]);
    }
};
