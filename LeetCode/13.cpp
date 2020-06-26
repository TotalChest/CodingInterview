class Solution {
public:
    map<char, int> Roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s) {
        int answer = 0, pred = 0;
        for (char c: s) {
            if (pred < Roman[c])
                answer -= 2 * pred;
            pred = Roman[c];
            answer += Roman[c];
        }
        return answer;
    }
};
