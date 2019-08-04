//2019-07-19 22:35:30
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	long* fi = new long[n + 1];

	fi[0] = 0;
	fi[1] = 1;
	fi[2] = 2;
	for (int i = 3; i <= n; i++) {
		fi[i] = fi[i - 2] + fi[i - 1];
		fi[i] %= 15746;
	}
	cout << fi[n];
	delete[] fi;



}