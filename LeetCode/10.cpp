class Solution {
public:
    bool Same(char a, char b) {
        return a == b || a == '.' || b == '.';
    }
    bool Pattern(string s, string p, int sp, int pp) {
        if (pp == -1 && sp != -1)
            return false;
        if (sp == -1)
            if (pp == -1 || (p[pp] == '*' && Pattern("", p, -1, pp - 2)))
                return true;
            else
                return false;
        if (Same(s[sp], p[pp]))
            return Pattern(s,p, sp - 1, pp - 1);
        if (p[pp] == '*')
            do {
                if (Pattern(s, p, sp, pp - 2))
                    return true;
            } while (sp >= 0 && Same(p[pp - 1], s[sp--]));
        return false;
    }
    bool isMatch(string s, string p) {
       return Pattern(s, p, s.size() - 1, p.size() - 1); 
    }
};
