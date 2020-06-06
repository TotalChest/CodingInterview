#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int k;
	cin >> k;
	vector<vector<int>> mas(k);

	for (int i = 0; i < k; ++i) {
		int len;
		cin >> len;
		mas[i] = vector<int>(len);
		for (int j = 0; j < len; ++j)
			cin >> mas[i][j]; 
	}

	vector<int> pos(k, 0);
	set<pair<int, int>> SET;
	for (int i = 0; i < k; ++i)
		if (mas[i].size() > 0)
			SET.insert(make_pair(mas[i][pos[i]], i));

	while (!SET.empty()) {
		auto min = *(SET.begin());
		SET.erase(SET.begin());
		int i = min.second;
		cout << min.first << ' ';
		++pos[i];
		if (pos[i] < mas[i].size())
			SET.insert(make_pair(mas[i][pos[i]], i));
	} 
	return 0;
}