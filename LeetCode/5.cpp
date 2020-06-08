class Solution {
public:
    int maxPalindrome(int l, int r, string &s) {
        int n = s.size();
        int dist = 0;
        while (l >= 0 && r < n && s[l] == s[r]) {
            dist = r - l + 1;
            --l;
            ++r;
        }
        return dist;
    }
    string longestPalindrome(string s) {
        int max_l = 0, max_r = 0;
        int n = s.size();
        if (n < 1)
            return "";
        for (int center = 0; center < n; ++center) {
            int first = maxPalindrome(center, center, s);
            int second = maxPalindrome(center, center + 1, s);
            first = max(first, second);
            if (max_r - max_l + 1 < first) {
                max_l = center - (first - 1) / 2;
                max_r = center + first / 2;
            }
        }
        return s.substr(max_l, max_r - max_l + 1);
    }
};
