//2019-07-19 22:03:10
#include <iostream>
using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C) {
		cout << -1;
	}
	else {
		cout << A / (C - B) + 1;
	}
}