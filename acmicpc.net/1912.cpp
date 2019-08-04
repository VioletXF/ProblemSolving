//2019-08-04 19:41:50
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> list(N, 0);
	vector<int> sumTo(N, 0);
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		list[i] = in;
	}
	sumTo[0] = list[0];
	int M = list[0];
	for (size_t i = 1; i < list.size(); i++) {
		sumTo[i] = max(sumTo[i - 1] + list[i], list[i]);
		M = max(M, sumTo[i]);
	}
	cout << M;
}