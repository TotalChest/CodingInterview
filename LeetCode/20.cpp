class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (const char c: s) {
            if (c == '(' || c == '[' || c == '{')
                S.push(c);
            else {
                if (S.empty())
                    return false;
                if ((c == ')' && S.top() == '(') ||
                    (c == '}' && S.top() == '{') ||
                    (c == ']' && S.top() == '['))
                    S.pop();
                else
                    return false;
            }
        }
        if (S.empty())
            return true;
        return false;
    }
};
