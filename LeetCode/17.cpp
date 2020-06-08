class Solution {
public:
    map<char, vector<char>> Phone;
    Solution() {
        Phone['2'] = vector<char>{'a','b','c'};
        Phone['3'] = vector<char>{'d','e','f'};
        Phone['4'] = vector<char>{'g','h','i'};
        Phone['5'] = vector<char>{'j','k','l'};
        Phone['6'] = vector<char>{'m','n','o'};
        Phone['7'] = vector<char>{'p','q','r','s'};
        Phone['8'] = vector<char>{'t','u','v'};
        Phone['9'] = vector<char>{'w','x','y','z'};
    }
    void generate(vector<string> &answer, string curr, int position, string &digits) {
        if (position == digits.size()) {
            answer.push_back(curr);
            return;
        }
        for (auto c: Phone[digits[position]])
            generate(answer, curr + c, position + 1, digits);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits.size() == 0)
            return answer;
        generate(answer, "", 0, digits);
        return answer;
    }
};
