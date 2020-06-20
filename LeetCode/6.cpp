class Solution {
public:
    string convert(string s, int numRows) {
        int  block = numRows > 1 ? 2 * numRows - 2 : 1;
        string answer = "";
        for (int i = 0; i < numRows; ++i) {
            int curr = i;
            while (curr < s.size()) {
                answer += s[curr];
                if (curr + (numRows - i - 1) * 2 < s.size() && i != 0 && i != numRows - 1)
                    answer += s[curr + (numRows - i - 1) * 2];
                curr += block;
            }
        }
        return answer;
    }
};
