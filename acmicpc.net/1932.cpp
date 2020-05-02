#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t[500][500];
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int input;
			cin >> input;
			if (i >= 1) {
				if (j == i) t[i][j] = t[i - 1][j - 1] + input;
				else if (j == 0) t[i][j] = t[i - 1][0] + input;
				else t[i][j] = max(t[i - 1][j - 1], t[i - 1][j]) + input;
			}
			else {
				t[i][j] = input;
			}
			if (i == n - 1) {
				res = max(res, t[i][j]);
			}
		}
	}
	cout << res;
}