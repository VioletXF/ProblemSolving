//2019-03-15 02:41:10
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		a = a % 10;
		int temp = a;
		for (int i = 0; i < b - 1; i++) {
			a = a * temp % 10;
		}
		if (a == 0)
			a = 10;
		cout << a << endl;
	}
}