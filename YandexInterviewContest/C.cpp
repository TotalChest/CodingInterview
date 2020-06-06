#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0)
		return 0;
	
	int curr, pred;
	cin >> pred;
	cout << pred << '\n';

	for (int i = 1; i < n; ++i) {
		cin >> curr;
		if (curr != pred)
			cout << curr << '\n';
		pred = curr;
	}

	return 0;
}