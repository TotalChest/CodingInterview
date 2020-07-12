class Solution {
public:
    int bin_search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int index = bin_search(nums, target);
        if (nums[index] == target)
            return index;
        if (nums[index] > target)
            return index;
        else
            return index + 1;
    }
};
