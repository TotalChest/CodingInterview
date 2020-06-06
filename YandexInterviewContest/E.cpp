#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string str, anagram;
	cin >> str >> anagram;

	map<char, int> S;
	for (int i = 0; i < 26; ++i)
		S['a' + i] = 0;

	for (const char ch: str)
		S[ch] += 1;

	for (const char ch: anagram)
		S[ch] -= 1;

	for (const auto elem: S)
		if (elem.second) {
			cout << 0;
			return 0;
		}

	cout << 1;
	return 0;
}