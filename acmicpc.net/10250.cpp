#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	short t, h, w, n;
	short floor, x;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		floor = (n-1) % h + 1;
		x = (n-1) / h + 1;
		cout << floor * 100 + x << "\n";
	}
}