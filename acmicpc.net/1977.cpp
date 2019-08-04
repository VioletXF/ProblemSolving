//2019-08-04 19:50:37
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	bool found = false;
	int sum = 0;
	int m = 10000;
	int start;
	int end;
	cin >> start >> end;
	for (int i = start; i <= end; i++) {
		double temp = sqrt((double)i);
		if (floor(temp) == temp) {
			found = true;
			m = min(m, i);
			sum += i;
		}
	}
	if (found) {
		cout << sum << "\n" << m;
	}
	else {
		cout << -1;
	}
}