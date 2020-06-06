#include <iostream>
#include <string>
using namespace std;

void F(string str, int s, int pos, int n) {
	if (pos == n) {
		cout << str << '\n';
		return;
	}
	if (s < n - pos)
		F(str + '(', s + 1, pos + 1, n);
	if (s > 0)
		F(str + ')', s - 1, pos + 1, n);
}

int main() {
	int n;
	cin >> n;

	F("", 0, 0, 2*n);
	return 0;
}