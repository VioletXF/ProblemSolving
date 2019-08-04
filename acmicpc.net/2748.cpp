//2019-07-19 22:50:21
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long* l = new long[n + 1];
	l[0] = 0;
	l[1] = 1;
	for (int i = 2; i <= n; i++) {
		l[i] = l[i - 1] + l[i - 2];
	}
	cout << l[n];
	delete l;
}