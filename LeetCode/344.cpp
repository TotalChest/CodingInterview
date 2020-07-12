class Solution {
public:
    void reverseString(vector<char>& s) {
        int r = 0, l = s.size() - 1;
        while (r < l)
            swap(s[l--], s[r++]);
    }
};
