#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int max = 0, curr_max = 0, curr; 
	for (int i = 0; i < n; ++i) {
		cin >> curr;
		if (curr == 1)
			++curr_max;
		else if (curr_max > max) {
			max = curr_max;
			curr_max = 0;
		}
		else
			curr_max = 0;
	}

	if (curr_max > max)
		cout << curr_max;
	else
		cout << max;

	return 0;
}