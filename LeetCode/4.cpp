class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        if (n == 0)
            if (m & 1)
                return (double)nums2[m/2];
            else
                return  ((double)(nums2[m/2] + nums2[(m-1)/2])) / 2;
        int l = 0, r = n, i, j;
        while (l <= r) {
            i = (l + r)/2;
            j = (n + m + 1) / 2 - i;
            int maxLeft_1 = i == 0 ? -1000000 :  nums1[i-1];
            int maxLeft_2 = j == 0 ? -1000000 :  nums2[j-1];
            int minRight_1 = i == n ? 1000000 : nums1[i];
            int minRight_2 = j == m ? 1000000 : nums2[j];
            if (maxLeft_1 <= minRight_2 && maxLeft_2 <= minRight_1) {
                if ((n + m) & 1)
                    return (double)max(maxLeft_1, maxLeft_2);
                else
                    return (double)(max(maxLeft_1, maxLeft_2) + min(minRight_1, minRight_2)) / 2;
            }
            else if (maxLeft_1 > minRight_2)
                r = i - 1;
            else
                l = i + 1;
        }
        return 0;
    }
};
