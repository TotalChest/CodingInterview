class Solution {
    vector<pair<int, string>> Voc = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
public:
    string intToRoman(int num) {
        string answer = "";
        for (auto elem: Voc) {
            while (num >= elem.first) {
                answer += elem.second;
                num -= elem.first;
            }
        }
        return answer;
    }
};
