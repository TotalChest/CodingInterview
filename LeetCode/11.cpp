class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1, l = 0, m = 0;
        while(l < r) {
            m = max(m, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r])
                ++l;
            else
                --r;
        }
        return m;
    }
};
