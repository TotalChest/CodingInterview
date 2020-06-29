class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";
        char curr_char;
        int curr_pos = 0;
        while (1) {
            curr_char = strs[0][curr_pos];
            for (auto s: strs)
                if (curr_pos >= s.size() || s[curr_pos] != curr_char)
                    return s.substr(0, curr_pos);
            curr_pos++;
        }
    }
};
