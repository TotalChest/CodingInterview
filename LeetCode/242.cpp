class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> char_freq(26, 0);
        for (auto c: s)
            char_freq[c - 'a'] += 1;
        for (auto c: t)
            char_freq[c - 'a'] -= 1;
        for (auto i: char_freq)
            if (i)
                return false;
        return true;
    }
};