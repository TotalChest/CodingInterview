class Solution {
public:
    int find_pivot (vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r])
                l = mid;
            else
                r = mid;
        }
        return l;
    }
    int bin_search(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int pivot = find_pivot(nums);
        int find = bin_search(nums, target, 0, pivot);
        if (find != -1)
            return find;
        else {
            find = bin_search(nums, target, pivot + 1, nums.size()- 1);
            return find;
        }
    }
};
