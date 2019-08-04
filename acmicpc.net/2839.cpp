//2019-07-19 22:38:03
#include <iostream>
using namespace std;
int main() {
	int n; 
	int t = 0, f = 0;
	cin >> n;
	while (n % 3 != 0) {
		n -= 5; 
		f++; 
	}
	if (n < 0)
		cout << -1; 
	else {
		t = n / 3;
		if (t >= 5) {
			f += (t / 5) * 3;
			t -= (t / 5) * 5;
		}
		cout << f + t; 
	} 
}