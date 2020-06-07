class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        int l = 0, r = 1, max = 1, n = s.size();
        unordered_set<char> SET;
        SET.insert(s[l]);
        while (r < n) {
            if (SET.find(s[r]) == SET.end()) {
                SET.insert(s[r]);
                ++r;
                if (r - l > max)
                    max = r - l;
            }
            else {
                SET.erase(s[l]);
                ++l;
            }
        }
        return max;
    }
};