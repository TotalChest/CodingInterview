class Solution {
public:
    void generate(vector<string> &list, string s, int opened, int closed, int n) {
        if (s.size() == 2*n) {
            list.push_back(s);
            return;
        }
        if (opened < n)
            generate(list, s + '(', opened + 1, closed, n);
        if (closed < opened)
            generate(list, s + ')', opened, closed + 1, n);    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        generate(list, "", 0, 0, n);
        return list;
    }
};
