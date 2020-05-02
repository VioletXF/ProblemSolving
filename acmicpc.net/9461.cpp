#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<unsigned long long> init = { 1,1,1,2,2 };
	init.resize(100);
	int T;
	int cur = 5;
	cin >> T;
	int N;
	while (T--) {
		cin >> N;
		--N;
		for (int i = cur; i <= N; i++) {
			init[i] = init[i - 1] + init[i - 5];
		}
		if (cur < N)cur = N;
		cout << init[N] << "\n";
	}
}