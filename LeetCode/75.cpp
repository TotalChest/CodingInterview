class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0, 0, 0};
        for(auto elem: nums)
            color[elem]++;
        int index = 0;
        for(int i = 0; i < 3; ++i)
            for (int j = 0; j < color[i]; ++j)
                nums[index++] = i;
    }
};
