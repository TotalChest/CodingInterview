class Solution {
public:
    int find_max(int target, vector<int> &nums, int l, int r) {
        while(l < r - 1) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid;
        }
        if (nums[r] == target)
            return r;
        if (nums[l] == target)
            return l;
        return -1;
    }
    int find_min(int target, vector<int> &nums, int l, int r) {
        while(l < r - 1) {
             int mid = (l+ r) / 2;
            if (nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        if (nums.size() == 0)
            return answer;
        answer[0] = find_min(target, nums, 0, nums.size()-1);
        answer[1] = find_max(target, nums, 0, nums.size()-1);
        return answer;
    }
};
