class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size())
            return 0;
        for(int i = 0; i <= (int)(haystack.size() - needle.size()); ++i) {
            for (int j = 0; j < needle.size(); ++j) {
                if (needle[j] != haystack[i + j])
                    break;
                if (j == needle.size() - 1)
                    return i;
            }
                
        }
        return -1;
    }
};
